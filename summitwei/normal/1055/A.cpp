#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int n, s;
pair<bool, bool> stats[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> n;
    F0R(i, s){
        int x;
        cin >> x;
        if(x){
            stats[i].fi = true;
        }
    }

    F0R(i, s){
        int x;
        cin >> x;
        if(x){
            stats[i].se = true;
        }
    }

    if(!stats[0].fi){
        cout << "NO\n";
        return 0;
    }

    if(stats[n-1].fi){
        cout << "YES\n";
        return 0;
    }

    if(stats[n-1].se){
        FOR(i, n, s-1){
            if(stats[i].fi && stats[i].se){
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;

    return 0;
}