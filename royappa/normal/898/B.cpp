#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pLL;

pLL eea2(LL a, LL b)
{
	if (a == 0)
	{
		return make_pair(1LL, 0LL);
	}
	else if (b == 0)
	{
		return make_pair(0LL, 1LL);
	}
	if (a % b == 0)
	{
		return make_pair(0LL, 1LL);
	}
	else
	{
		pLL t = eea2(b, a % b);
		LL m = t.first, n = t.second;

		return make_pair(n, m-n*(a / b));
	}
}

// reference: https://math.stackexchange.com/questions/1310415/extended-euclidean-algorithm-with-negative-numbers-minimum-non-negative-solution?rq=1

bool neg(LL x) { return x < 0; }
int main()
{
	int a, b, n;
	cin >> n >> a >> b;
	if (n%__gcd(a, b) != 0) {
			cout << "NO" << endl;
	}
	else {
		pLL z = eea2(a, b);
		LL s = z.first, t = z.second;
		LL aa = a/__gcd(a,b);
		LL bb = b/__gcd(a,b);
		// next is based on bounds given in reference
		//g*(s+k*bb)*a + g*(t-k*aa)*b = n;
		//s*a+k*bb*a + t*b-k*aa*b = n/g
		// s*a+t*b + k*(bb*a-aa*b) = n/g
		// want s+k*bb >= 0 and t-k*aa >= 0
		// means k >= -s/bb  and k <= t/aa
		// k = [n-(s*a+t*b)]/(bb*a-aa*b);
		int m = n/__gcd(a,b);
		s *= m;
		t *= m;
		while (s < 0 || t < 0) {
			int ns = neg(s), nt = neg(t);
			if (s < 0) {
				s += bb;
				t -= aa;
			}
			else if (t < 0) {
				s -= bb;
				t += aa;
			}
			if ((!ns&&neg(s)) || (!nt&&neg(t))) {
				cout << "NO" << endl;
				exit(0);
			}
		}
		cout << "YES" << endl;
		cout << s << " " << t << endl;
	}
	exit(0);
}