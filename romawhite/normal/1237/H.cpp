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
const int MAX = 4007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);
 
int res[MAX];
 
int ids[MAX];
 
int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);
 
	int t;
	cin >> t;
	FOR(tt,0,t)
	{
		string a;
		string b;
		cin >> a >> b;
		int n = SZ(a) / 2;
		VI A(2 * n), B(2 * n);
		FOR(i,0,2*n)
		{
			A[i] = a[i] - '0';
			B[i] = b[i] - '0';
		}
		int SA[3];
		int SB[3];
		FOR(i,0,3)
			SA[i] = SB[i] = 0;
		
		FOR(i,0,n)
		{
			SA[A[2 * i] + A[2 * i + 1]] ++;
			SB[B[2 * i] + B[2 * i + 1]] ++;
		}
		bool ok = true;
		FOR(i,0,3)
			ok &= (SA[i] == SB[i]);
		if (!ok)
		{
			cout << -1 << endl;
			continue;
		}
 
 
		while(true)
		{
		    FOR(i,0,2*n)
    		{
    			A[i] = a[i] - '0';
    			B[i] = b[i] - '0';
    		}
 
			int m = 0;
			int k = 2 * n;
			while(k > 0)
			{
				if (m > 2 * n + 1)
				{
					break;
				}
				if (A[k - 2] == B[k - 2] && A[k - 1] == B[k - 1])
				{
					k -= 2;
					continue;
				}
				if (A[0] == B[k - 1] && A[1] == B[k - 2])
				{
					res[m ++] = k;
					FOR(i,0,k / 2)
						swap(A[i], A[k - 1 - i]);
					k -= 2;
					continue;
				}
				if (A[0] == B[k - 2] && A[1] == B[k - 1])
				{
					res[m ++] = 2;
					swap(A[0], A[1]);
					res[m ++] = k;
					FOR(i,0,k / 2)
						swap(A[i], A[k - 1 - i]);
					k -= 2;
					continue;
				}
				int c = 0;
				for(int i = 0; i < k; i += 2)
				{
					if (A[i] == B[k - 2] && A[i + 1] == B[k - 1])
					{
						ids[c ++] = i;
					}
				}
				if (c > 0)
				{
					int id = ids[rand() % c];
					res[m ++] = id + 2;
					FOR(i,0,(id + 2) / 2)
					{
						swap(A[i], A[id + 2 - i - 1]);
					}
					res[m ++] = k;
					FOR(i,0,k / 2)
					{
						swap(A[i], A[k - i - 1]);
					}
					k -= 2;
					continue;
				}
				for(int i = 0; i < k; i += 2)
				{
					if (A[i] == B[k - 1] && A[i + 1] == B[k - 2])
					{
						ids[c ++] = i;
					}
				}
				int id = ids[rand() % c];
				res[m ++] = id + 2;
				FOR(i,0,(id + 2) / 2)
				{
					swap(A[i], A[id + 2 - i - 1]);
				}
				res[m ++] = 2;
				swap(A[0], A[1]);
				res[m ++] = k;
				FOR(i,0,k / 2)
				{
					swap(A[i], A[k - i - 1]);
				}
				k -= 2;
				continue;
			}
 
			if (m <= min(2 * n + 1, 3 * n / 2 + 2))
			{
				// assert(A == B);
				cout << m << endl;
				FOR(i,0,m)
				{
					cout << res[i] << ' ';
				}
				cout << endl;
				break;
			}
		}
 
		
	}
 
 
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}