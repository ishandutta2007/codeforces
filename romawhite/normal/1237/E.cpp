#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);
 
int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);
 
    int n;
	cin >> n;
	
	if (n == 1 || n == 2){
		cout << 1 << endl;
		return 0;
	}	

	vector<PII> A;
	A.push_back(MP(4, 2));
	A.push_back(MP(5, 3));

	int res = 0;

	while (SZ(A))
	{
		FOR(i,0,SZ(A))
		{
			if (A[i].first == n)
				++res;
			// cout << A[i].first << ' ' << A[i].second << endl;
		}
		vector<PII> B;

		FOR(i,0,SZ(A))
			FOR(j,0,SZ(A))
			{
				if (A[i].first > n)
					continue;
				if (A[j].first > n)
					continue;
				int root = A[i].first + 1;
				if (root % 2 == A[i].second % 2)
					continue;
				int sr = root + A[j].second;
				if (sr % 2 != root % 2)
					continue;
				B.push_back(MP(A[i].first + 1 + A[j].first, sr));
			}
		A = B;
	}
	
	cout << res << endl;
 
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}