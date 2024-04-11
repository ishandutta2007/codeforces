#include <bits/stdc++.h>
using namespace std;

const int N = 311;
const double Eps = 1e-12;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}
typedef pair <double, double> pdd;
#define x first
#define y second

vector <pdd> conv[N];

vector <pdd> solve(vector <pdd> v, double sy, double k)
{
	vector <pdd> ret;
	for(int i = 0; i < v.size(); i ++)
	{
		double ty = sy + k * v[i].x;
		double ly = (i == 0) ? 0 : sy + k * v[i - 1].x;
		if(i > 0 && sgn(ly, v[i - 1].y) * sgn(ty, v[i].y) < 0)
		{
			double tk = k - (v[i].y - v[i - 1].y) / (v[i].x - v[i - 1].x);
			double ix = (v[i - 1].y - ly) / tk + v[i - 1].x;
			double iy = sy + k * ix;
			ret.push_back({ix, iy});
		}
		if(sgn(v[i].y, ty) >= 0)
			ret.push_back(v[i]);
		else if(i == 0)
			ret.push_back({0, ty});
		else if(i + 1 == v.size())
			ret.push_back({1, ty});
	}
	return ret;
}

double area(const vector <pdd> &v)
{
	double ret = 0;
	for(int i = 1; i < v.size(); i ++)
		ret += (v[i - 1].y + v[i].y) * (v[i].x - v[i - 1].x) / 2;
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i ++)
		conv[i] = {{0, 0}, {1, 0}};
	double la = 0;
	cout << setprecision(6);
	for(int i = 0; i < n; i ++)
	{
		int last;
		cin >> last;
		double ta = 0;
		for(int j = 0; j < k; j ++)
		{
			int now;
			cin >> now;
			conv[j] = solve(conv[j], last, now - last);
			last = now;
			ta += area(conv[j]);
		}
		cout << ta - la << '\n';
		la = ta;
	}
	return 0;
}