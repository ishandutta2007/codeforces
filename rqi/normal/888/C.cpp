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
	string se;
	cin >> se;
	int ans = 100000;
	char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	for(int i = 0; i < 26; i++){
	    int ans1 = 0;
	    int first = -1;
	    int second = -1;
	    for(int j = 0; j < se.length(); j++){
	        if(se[j] == letters[i]){
	            second = j;
	        }
	        ans1 = max(ans1, second-first);
	        first = second;
	    }
	    ans1 = max(ans1, int(se.length())-second);
	    if(ans1 != 0){
	        ans = min(ans, ans1);
	    }
	}
	cout << ans;
}

// read!
// ll vs. int!