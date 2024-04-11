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
	vector<pair<PII, PII> > A;
	FOR(i,0,n)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		A.push_back(MP(MP(x, y), MP(z, i)));
	}

	sort(ALL(A));
	
	vector<PII> res;

	vector<pair<PII, PII> > B, C;
	FOR(i,0,n)
	{
		if (SZ(B) && B.back().first == A[i].first)
		{
			res.push_back(MP(B.back().second.second, A[i].second.second));
			B.pop_back();
		}
		else
		{
			B.push_back(A[i]);
		}
	}

	FOR(i,0,SZ(B))
	{
		if (SZ(C) && C.back().first.first == B[i].first.first)
		{
			res.push_back(MP(C.back().second.second, B[i].second.second));
			C.pop_back();
		}
		else
		{
			C.push_back(B[i]);
		}
	}

	for(int i = 0; i < SZ(C); i += 2)
		res.push_back(MP(C[i].second.second, C[i + 1].second.second));

	FOR(i,0,SZ(res))
	{
		cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
	}
 
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}