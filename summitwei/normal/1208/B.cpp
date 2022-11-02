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
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n;
int a[MN];
multiset<int> ree;
int dup;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        if(ree.count(a[i])) ++dup;
        ree.insert(a[i]);
    }
    int ans = INF;
    if(dup == 0){
        cout << "0\n";
        return 0;
    }
    int j = 0;
    F0R(i, n){
        while(j < n && dup != 0){
            //cout << i << " " << j << " " << dup << "\nvals: ";
            //for(auto u : ree) cout << u << " ";
            //cout << "\n";
            if(ree.count(a[j]) > 1) --dup;
            ree.erase(ree.find(a[j]));
            
            ++j;
        }
        if(dup == 0) ans = min(ans, j-i);
        //cout << "res: " << i << " " << j << " " << dup << "\n";
        if(ree.count(a[i])) ++dup;
        ree.insert(a[i]);
    }
    cout << ans << "\n";

    return 0;
}