#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

ll N, M, X, Y, A, B;

ll solve (ll sz, ll tot, ll x)
{
	if (2 * x >= sz && 2 * (tot - x) >= sz)
		return x - (sz + 1) / 2;
	if (2 * x < sz)
		return 0;
	return tot - sz;
}

ll gcd (ll x, ll y)
{
	if (y == 0)
		return x;
	return gcd (y, x % y);
}

int main()
{
	cin >> N >> M >> X >> Y >> A >> B;
	
	bool check = false;
	if (N * B > M * A) // M is limiting
	{
		swap (N, M);
		swap (X, Y);
		swap (A, B);
		
		check = true;
	}
	
	ll g = gcd (A, B);
	A /= g;
	B /= g;
	
	ll len = (N - (N % A));
	ll wid = len * B / A;
	
	//cout << len << " " << N << " " << X << "\n";
	
	ll x1 = solve (len, N, X);
	ll y1 = solve (wid, M, Y);
	ll x2 = x1 + len;
	ll y2 = y1 + wid;
	
	if (check)
	{
		swap (x1, y1);
		swap (x2, y2);
	}
	
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	return 0;
}