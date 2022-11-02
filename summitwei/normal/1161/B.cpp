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

#define MN 100005
int n, m;
vi e[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[a].pb((b-a+n)%n);
        e[b].pb((a-b+n)%n);
    }
    F0R(i, n){
        sort(e[i].begin(), e[i].end());
    }

    FOR(i, 1, n-1){
        if(n % i != 0) continue;

        bool ok = true;

        F0R(j, n){
            int o = (i+j)%n;
            if(e[j].size() != e[o].size()){
                ok = false;
                break;
            }
            F0R(k, e[j].size()){
                if(e[j][k] != e[o][k]){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
    
    return 0;
}