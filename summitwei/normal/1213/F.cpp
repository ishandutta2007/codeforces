#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, k;
int p[MN];
int ip[MN];
int q[MN];
int iq[MN];

int ans[MN];

void dfs(int cn, int ch){
    if(ans[cn] != -1) return;
    ans[cn] = ch;
    //cout << "doing " << cn << " " << ch << "\n";

    if(ip[cn] != n){
        dfs(p[ip[cn]+1], ch);
    }
    if(iq[cn] != n){
        dfs(q[iq[cn]+1], ch);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 1, n){
        cin >> p[i];
        ip[p[i]] = i;
    }
    FOR(i, 1, n){
        cin >> q[i];
        iq[q[i]] = i;
    }
    memset(ans, -1, sizeof ans);
    bool ok = false;
    RFOR(i, n, 1){
        if(ans[p[i]] == -1){
            dfs(p[i], k);
            if(k == 1) ok = true;
            k = max(k-1, 1);
        }
    }

    if(!ok){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    FOR(i, 1, n){
        cout << (char)(ans[i]+'a'-1);
    }

    return 0;
}