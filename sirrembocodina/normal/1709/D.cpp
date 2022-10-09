#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define int int64_t

// Type aliases

using ll = long long;
using str = string;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Vector Operations

#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)

// Pairs

#define mp make_pair
#define sec second
#define fir first

// Sets and Maps

#define ins insert
#define ez erase
#define cnt count

// Math

#define MAX_INT 1e18*9

// Loops

#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define printv(v) cout << "["; for(int i =0;i<v.size();i++){ cout << v[i]; if(i!=v.size()-1){ cout << ", "; } } cout << "]" << endl;

// To check time of submission, put below line after reading input
// clock_t z = clock();
#define time_up cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "\n";

// __gcd(20, 60) for in-built GCD function

int MOD = 1e9 + 7;

// C++ program for range minimum
// query using segment tree
#include <bits/stdc++.h>
using namespace std;

// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? y: x; }

// A utility function to get the
// middle index from corner indexes.
int getMid(int s, int e) { return s + (e -s)/2; }

/* A recursive function to get the
minimum value in a given range
of array indexes. The following
are parameters for this function.

    st --> Pointer to segment tree
    index --> Index of current node in the
           segment tree. Initially 0 is
           passed as root is always at index 0
    ss & se --> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[index]
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part
    // of given range, then return
    // the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node
    // is outside the given range
    if (se < qs || ss > qe)
        return 0;

    // If a part of this segment
    // overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range
// from index qs (query start) to
// qe (query end). It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se,
                                int *st, int si)
{
    // If there is one element in array,
    // store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements,
    // then recur for left and right subtrees
    // and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                    constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

void solve() {
	int n, m;
	cin >> n >> m;
	int a[200005];
	for(int i = 0; i < m; i++) cin >> a[i];
	int *st = constructST(a, 200005);
	int q;
	cin >> q;
	while(q--){
		bool valid = true;
		int y1, x1, y2, x2, k;
		cin >> y1 >> x1 >> y2 >> x2 >> k;
		x1--; x2--;
		if((x2 - x1) % k || (y2 - y1) % k) valid = false;
		if(valid){
			int moveUp = (n - y1)/k;
			y1 += moveUp * k;
			int max_q;
			if(x1 < x2) max_q = RMQ(st, 200005, x1, x2);
			else max_q = RMQ(st, 200005, x2, x1);
			if(max_q >= y1) {
				valid = false;
			}
		}
		if(valid) cout << "YES\n";
		else cout << "NO\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}