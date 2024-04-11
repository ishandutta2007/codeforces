#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n, k;
	cin >> n >> k;
	if(k == 1){
	    cout << 1;
	}
	if(k == 2){
	    cout << n*(n-1)/2 + 1;
	}
	if(k == 3){
	    cout << n*(n-1)*(n-2)/6*2 + n*(n-1)/2 + 1;
	}
	if(k == 4){
	    cout << n*(n-1)*(n-2)*(n-3)/24*9 + n*(n-1)*(n-2)/6*2 + n*(n-1)/2 + 1;
	}
}

// read!
// ll vs. int!