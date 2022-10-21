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
unsigned long long power(unsigned long long a){
    unsigned long long b = 1;
    for(unsigned long long i = 0; i < a; i++){
        b*=2;
    }
    return b;
}
unsigned long long aa[100];
int main() {
	//ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	unsigned long long n, k;
	cin >> n >> k;
	if(k == 1) cout << n;
	else{
	 unsigned long long maxj = 0;
	 while(n > 0){
	    unsigned long long j = 1;
	    unsigned long long a = 0;
	    while(j <= n){
	        j*=2;
	        a++;
	    }
	    a--;
	    j/=2;
	    
	    maxj = max(maxj, a);
	    n-=j;
	    aa[a] = 1;
	}

	k--;
    unsigned long long ans = 0;
    unsigned long long cc = 0;
	for(unsigned long long i = 0; i < k && cc < maxj+1; cc++){
	    if(aa[maxj-cc] == 0){
	        aa[maxj-cc] = 1;
	        i++;
	    }
	}
	for(unsigned long long i = 0; i < maxj+1; i++){
	    ans+=aa[i]*power(i);
	}
	
	cout << power(maxj+1)-1;
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!