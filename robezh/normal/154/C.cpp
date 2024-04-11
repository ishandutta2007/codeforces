#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int N = (int)1e6 + 500;

struct hs{
    ll val[4];
    hs(){fill(val, val+4, 0);}
    hs(ll a, ll b, ll c, ll d){
        val[0] = a, val[1] = b, val[2] = c, val[3] = d;
    }
    bool operator < (const hs &other) const{
        for(int i = 0; i < 4; i++) if(val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }
    bool operator == (const hs &other) const{
        for(int i = 0; i < 4; i++) if(val[i] != other.val[i]) return false;
        return true;
    }
}num[N];

ll pw[4][N];
int n,m;
ll ful = 1;
int a[N], b[N];

int p = 2;
//ll mod = (1LL << 31);


int main(){
    for(int t = 0; t < 4; t++){
        pw[t][0] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a[i], &b[i]);
        a[i]--, b[i]--;

    }
    ll res = 0;
    for(int t = 0; t < 2; t++){
        fill(num, num+n, hs());
        for(int md = 0; md < 4; md++){
            for(int i = 0; i < m; i++){
                num[a[i]].val[md] += pw[md][b[i]];
                num[b[i]].val[md] += pw[md][a[i]];
                num[a[i]].val[md] %= mods[md];
                num[b[i]].val[md] %= mods[md];
            }
        }

        if(t == 0){
            for(int md = 0; md < 4; md++)
                for(int i = 0; i < n; i++)
                    num[i].val[md] = (num[i].val[md] + pw[md][i]) % mods[md];
        }

        sort(num, num+n);
        int r = 0;
        for(int i = 0; i < n;){
            while(r < n && num[r] == num[i]) r++;
            res += 1LL * (r - i) * (r - i - 1) / 2;
            i = r;
        }
    }
    cout << res << endl;

}