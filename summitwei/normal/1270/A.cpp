#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        int n, k1, k2;
        int l1=0, l2=0;
        cin >> n >> k1 >> k2;
        F0R(_, k1){
            int x;
            cin >> x;
            l1 = max(l1, x);
        }
        F0R(_, k2){
            int x;
            cin >> x;
            l2 = max(l2, x);
        }
        if(l1 > l2){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    
    return 0;
}