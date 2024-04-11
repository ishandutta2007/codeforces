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
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

ll squared[MAX_N][MAX_N];
ll n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 0;

    cin >> n >> m;
    FOR(i, 1, min(n, m)){
        FOR(j, 1, min(n, m)){
            squared[i][j] = (i*i+j*j)%m;
            if(squared[i][j] == 0){
                ll amtI = (n-i)/m+1;
                ll amtJ = (n-j)/m+1;
                ans += (amtI*amtJ);
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}