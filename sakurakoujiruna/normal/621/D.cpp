#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long double doublel;

const doublel Eps = 1e-15;
bool equal(doublel a, doublel b)
{
	if(fabsl(a - b) < Eps)
		return true;
	if(fabsl(a - b) < Eps * fabsl(a))
		return true;
	return false;
}

string str[12] = {
	"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
	"y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
	"z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"
};

doublel ans[12];

int main()
{
	//cout << setprecision(20) << log1pl(1e-5) << '\n';
	//cout << setprecision(20) << logl(1 + 1e-5) << '\n';

	ios :: sync_with_stdio(false);
	doublel x, y, z;
	cin >> x >> y >> z;
	
	ans[0] = powl(y, z) * logl(x);
	ans[1] = powl(z, y) * logl(x);
	ans[2] = ans[3] = y * z * logl(x);

	ans[4] = powl(x, z) * logl(y);
	ans[5] = powl(z, x) * logl(y);
	ans[6] = ans[7] = x * z * logl(y);

	ans[8] = powl(x, y) * logl(z);
	ans[9] = powl(y, x) * logl(z);
	ans[10] = ans[11] = x * y * logl(z);

	int p = 0;
	for(int i = 1; i < 12; i ++)
		if(!equal(ans[i], ans[p]) && ans[i] > ans[p])
			p = i;

	cout << str[p] << '\n';
	return 0;
}