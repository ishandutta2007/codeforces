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
*/
ll ways[5000][5000]; //this many lines, this many indents.
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll N;
	cin >> N;
	bool lastf = false;
	ll fnum = 0;
	for(ll i = 0; i < N; i++){
	    char a;
	    cin >> a;
	    if(i == 0){
	          if(a == 'f'){
	              ways[0][0] = 1;
	              lastf = true;
	              fnum++;
	          }
	          else{
	              ways[0][0] = 1;
	          }
	    }
	    else{
	        if(a == 'f'){
	            if(lastf == true){
	                for(ll j = 1; j < fnum+1; j++){
	                    ways[i][j] = ways[i-1][j-1];
	                }
	                fnum++;
	            }
	            else{
	                for(ll j = fnum; j >=0; j--){
	                    /*for(ll k = fnum; k >= j; k--){
	                        ways[i][j] += ways[i-1][k];
	                        ways[i][j]%=MOD;
	                    }*/
	                    ways[i][j] =ways[i][j+1] + ways[i-1][j];
	                    ways[i][j]%= MOD;
	                }
	                lastf = true;
	                fnum++;
	            }
	        }
	        else{
	            if(lastf == true){
	                lastf = false;
	                for(ll j = 1; j < fnum+1; j++){
	                    ways[i][j] = ways[i-1][j-1];
	                }
	            }
	            else{
	                for(ll j = fnum; j >=0; j--){
	                    /*for(ll k = fnum; k >= j; k--){
	                        ways[i][j] += ways[i-1][k];
	                        ways[i][j]%=MOD;
	                    }*/
	                    ways[i][j] =ways[i][j+1] + ways[i-1][j];
	                    ways[i][j]%= MOD;
	                }
	            }
	        }
	    }
	}
	ll ans = 0;
	for(ll i = 0; i < fnum+1; i++){
	    ans+= ways[N-1][i];
	    ans%=MOD;
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!