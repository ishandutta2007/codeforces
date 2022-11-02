#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define INFLL 2000000000000000000LL
#define MOD 1000000007LL
#define EPS 0.000000000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005 //check limits you incompetent ree
int n; ll k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n >> k;
        --k;
        if(n <= 60 && k >= (1LL<<(n-1))){
            cout << "-1\n";
            continue;
        }
        int pv = 1;
        int cur = 1;
        while(pv != n+1){
            int ree = n-1-cur;
            if(ree > 60) ree = 60;
            if(ree < 0) ree = 0;
            ll amt = 1LL<<ree;
            if(k >= amt && cur < n){
                cur++;
                k -= amt;
            } else{
                RFOR(i, cur, pv){
                    cout << i << " ";
                }
                pv = cur+1; cur = cur+1;
            }
        }
        cout << "\n";
    }

    return 0;
}