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
	int q = 0;

	FOR(i,0,n)
	{
		int x;
		cin >> x;
		if (x % 2 == 0)
		{
			cout << x / 2 << endl;
		}
		else
		{
			int y = (x > 0 ? x / 2 : -(-x / 2) - 1) + q;
			cout << y << endl;
			q ^= 1;
		}
	}
 
 
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}