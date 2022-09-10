#include <bits/stdc++.h>
#define int long long
#define ll long long
#define VPI vector<pair<int,int>>
#define pb push_back
#define eb emplace_back
#define st first
#define nd second
using namespace std;

const int N = 1e5+7;
const int K = 1e6+7;
const int mod = 1e9+7;
const int LOG = 20;

int n, k, res;

VPI g[N];

int dp[N][LOG];

int pot[K];

int h[N];

int gora[N][LOG],dol[N][LOG];

void dfs(int v, int p){
    dp[v][0] = p;
    h[v] = h[p] + 1;

    for(auto it:g[v]){
        if (it.st != p){
            dfs(it.st, v);
        }
    }

    return;
}

int lca(int a, int b){
    if (h[a] < h[b]){
        swap(a,b);
    }

    for(int i = LOG - 1; i >= 0; i--){
        if (h[a] - (1<<i) >= h[b]){
            a = dp[a][i];
        }
    }

    if  (a == b){
        return a;
    }

    for(int i = LOG - 1; i >= 0; i--){
        if (dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    return dp[a][0];
}

void dodajGora(int a, int b){
    for(int i = LOG - 1; i >= 0; i--){
        if (h[a] - (1<<i) >= h[b]){
            gora[a][i]++;
            a = dp[a][i];
        }
    }
}

void dodajDol(int a, int b){
    for(int i = LOG - 1; i >= 0; i--){
        if (h[a] - (1<<i) >= h[b]){
            dol[a][i]++;
            a = dp[a][i];
        }
    }
}

void policz(int v, int p){
    for(auto it:g[v]){
        if (it.st != p){
            policz(it.st,v);

               // cout << v << " " << it.st << " " << it.nd << " " << gora[it.st][0] << " " << dol[it.st][0] << endl;

            if (it.nd == 1 && gora[it.st][0]){
                res += pot[gora[it.st][0]] - 1;
                res %= mod;
            }

            if (it.nd == -1 && dol[it.st][0] > 0){
                res += pot[dol[it.st][0]] - 1;
                res %= mod;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    pot[0] = 1;

    for(int i = 1; i <= 1000*1000+3; i++){
        pot[i] = pot[i-1]*2%mod;
    }

    cin >> n;

    for(int i = 1; i <= n - 1; i++){
        int a,b,c;
        cin >> a >> b >> c;

        g[a].eb(b,c);
        g[b].eb(a,-c);
    }

    dfs(1,1);

    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    cin >> k;

    int current = 1;

    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;

        int curLca = lca(current, x);

        dodajGora(current, curLca);
        dodajDol(x, curLca);

      //  cout << current << " " << x << " " << curLca << endl;

        current = x;
    }

    for(int i = LOG - 1; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            gora[j][i-1] += gora[j][i];
            gora[dp[j][i-1]][i-1] += gora[j][i];

            dol[j][i-1] += dol[j][i];
            dol[dp[j][i-1]][i-1] += dol[j][i];
        }
    }

    policz(1,1);

    cout << res;

    return 0;
}