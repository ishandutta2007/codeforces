#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int K = 4, B = 26, N = 255;
const int mods[K] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};


int n,m;
string s[N];
int p = 377;
ll pw[K][B];

struct hs {
    ll val[K];
    bool good;

    hs(){fill(val, val + K, 0); good = true;}
    hs(int cnt[]) {
        fill(val, val + K, 0);
        for(int k = 0; k < K; k++) {
            for(int i = 0; i < B; i++) {
                val[k] += pw[k][i] * cnt[i] % mods[i];
                val[k] %= mods[i];
            }
        }
    }

    hs(ll a) {
        fill(val, val + K, a);
        good = true;
    }

    bool operator<(const hs &other) const {
        for (int i = 0; i < K; i++) if (val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }

    bool operator==(const hs &other) const {
        for (int i = 0; i < K; i++) if (val[i] != other.val[i]) return false;
        return true;
    }

    hs operator + (const hs &other) const{
        hs res;
        for(int i = 0; i < K; i++) res.val[i] = ( val[i] + other.val[i]) % mods[i];
        return res;
    }

    hs operator - (const hs &other) const{
        hs res;
        for(int i = 0; i < K; i++) res.val[i] = (val[i] - other.val[i] + mods[i]) % mods[i];
        return res;
    }

    void add(int j) {
        for(int i = 0; i < K; i++) val[i] = (val[i] + pw[i][j]) % mods[i];
    }
};


struct Manacher {
    vector<hs> s, sn;
    int p[2*N];

    int Init()
    {
        int len = s.size();
        sn.push_back(hs(-2));
        hs delim = hs(-1);
        sn.push_back(delim);
        int j = 2;

        for (int i = 0; i < len; i++)
        {
            sn.push_back(s[i]);
            sn.push_back(delim);
        }

        sn.push_back(hs());

        return sn.size();  //  sn 
    }

    int run()
    {
        int res = 0;
        int len = Init();  //  sn 
        int max_len = -1;  // 

        int id = 0;
        int mx = 0;
//
//        for(int i =0; i < len; i++) cout << sn[i].val[0] << " ";
//        cout << endl;

        for (int i = 1; i < len; i++)
        {
            if (i < mx)
                p[i] = min(p[2 * id - i], mx - i);  // , mx  2*id-i 
            else
                p[i] = 0;

            while (sn[i - p[i]] == sn[i + p[i]] && sn[i-p[i]].good && sn[i+p[i]].good)  // '$','\0'
                p[i]++;

            //  i mx  mx  if (i < mx)
            if (mx < i + p[i])
            {
                id = i;
                mx = i + p[i];
            }
            if(sn[i].good) res += p[i] / 2;
//            if(p[i] / 2 > 0) cout << ", " << p[i] / 2 << endl;
        }
        return res;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int t = 0; t < K; t++){
        pw[t][0] = 1;
        for(int i = 1; i < B; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    int res = 0;
    for(int l = 0; l < m; l++) {
        vector<hs> hss(n, hs());
        int cnt[N][B];
        int o_cnt[N];
        memset(cnt, 0, sizeof(cnt));
        memset(o_cnt, 0, sizeof(o_cnt));
        for(int r = l; r < m; r++) {
            for(int i = 0; i < n; i++) {
                if(cnt[i][s[i][r]-'a'] % 2 ==  0) o_cnt[i] ++;
                else o_cnt[i] --;
                cnt[i][s[i][r] - 'a'] ++;
                hss[i].add(s[i][r] - 'a');
                hss[i].good = (o_cnt[i] <= 1);
            }
            Manacher mnc;
            mnc.s = hss;
            res += mnc.run();
//            cout << l << " to " << r << ": " << mnc.run() << endl;
        }
    }
    cout << res << endl;

}