#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int N = (int)6e5 + 500;

struct hs {
    ll val[4];

    hs() { fill(val, val + 4, 0); }

    hs(ll a, ll b, ll c, ll d) {
        val[0] = a, val[1] = b, val[2] = c, val[3] = d;
    }

    bool operator<(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }

    bool operator==(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return false;
        return true;
    }
    hs operator + (const hs &other) const {
        hs res = hs();
        for(int i = 0; i < 4; i++) res.val[i] = (val[i] + other.val[i]) % mods[i];
    }
};


int p = 17;
int n,m;
ll pw[4][N];
set<hs> S;
string s[N], t[N];


void add(hs &to, int x, int px){
    for(int i = 0; i < 4; i++){
        to.val[i] += x * pw[i][px];
        to.val[i] = (to.val[i] % mods[i] + mods[i]) % mods[i];
    }
}

bool check(string str){
    hs hsh;
    for(int i = 0; i < str.length(); i++){
        add(hsh, str[i]-'a'+1, i);
    }
    for(int i = 0; i < str.length(); i++){
        for(int j = 0; j < 3; j++){
            if(str[i] - 'a' != j){
                add(hsh, -(str[i]-'a')+j, i);
                if(S.find(hsh) != S.end()) return true;
                add(hsh, +(str[i]-'a')-j, i);
            }
        }
    }
    return false;
}

int main(){
    for(int t = 0; t < 4; t++){
        pw[t][0] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }

    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, s[i]);
        hs hsh;
        for(int j = 0; j < s[i].length(); j++){
            add(hsh, s[i][j] - 'a' + 1, j);
        }
        S.insert(hsh);
    }
    for(int i = 0; i < m; i++){
        getline(cin, t[i]);
        if(check(t[i])) printf("YES\n");
        else printf("NO\n");
    }
}