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
/*
CUML SUM
DFS BFS BIN SEARCH
STRUCTS
TWOPOINT
GREEDY
Data Structures
Basic 1D Range Queries
Graphs
Shortest Path
Topological Sort
Strings
Hashing
Trees
MST
Dynamic Programming
Intro
DP
DSU
*/

ll V[100006];
ll T[100006];
ll sumt[100006];
ll onesums[100006];
ll sums[100006];
ll ans1[100006];
ll ans[100006];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll N;
	cin >> N;
	for(ll i = 0; i < N; i++){
	    cin >> V[i];
	}
	for(ll i = 0; i < N; i++){
	    cin >> T[i];
	}
	sumt[0] = T[0];
	for(ll i = 1; i < N; i++){
	    sumt[i] = sumt[i-1]+T[i];
	}
	for(ll i = 0; i < N; i++){
	    
	    ll f = 0;
	    if(i-1 >= 0){
	        f = sumt[i-1];
	    }
	    auto k = upper_bound(sumt+i,sumt+N,V[i]+f)-sumt;
	    if(k < N && k > 0){
            onesums[k-1]++;
            if(i-1 >= 0) onesums[i-1]--;
            sums[k] += V[i]+f-sumt[k-1];
	    }
	    else if(k == 0){
	        sums[k]+=V[i];
	    }
	    else if(k == N){
	        onesums[k-1]++;
	        if(i-1 >= 0) onesums[i-1]--;
	    }
	}
	ans1[N-1] = onesums[N-1];
	for(int i = N-2; i >= 0; i--){
	    ans1[i] = ans1[i+1]+onesums[i];
	}
	for(int i = 0; i < N; i++){
	    ans[i] = ans1[i]*T[i]+sums[i];
	}
	for(int i = 0; i < N; i++){
	    cout << ans[i] << " ";
	}
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!