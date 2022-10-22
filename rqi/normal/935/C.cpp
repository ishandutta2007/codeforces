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
*/
double R, xa1, ya1;
double xa2, ya2, ansx, ansy, r, distx, disty, dist;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	cin >> R >> xa1 >> ya1 >> xa2 >> ya2;
	if((xa2-xa1)*(xa2-xa1) + (ya2-ya1)*(ya2-ya1) > R*R){
	    ansx = xa1;
	    ansy = ya1;
	    r = R;
	}
	else{
	    distx = xa1-xa2;
	    disty = ya1-ya2;
	    dist = sqrt(distx*distx+disty*disty);
	    if(dist == 0){
	        ansx = xa1-R/2;
	        ansy = ya1;
	        r = R/2;
	    }
	    else{
	        ansx = (xa2+distx*(R+dist)/dist+xa2)/2;
	        ansy = (ya2+disty*(R+dist)/dist+ya2)/2;
	        r = (R+dist)/2;
	    }
	}
	cout << setprecision(15) << ansx << " " << ansy << " " << r;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!