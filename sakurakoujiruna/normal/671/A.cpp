#include <bits/stdc++.h>
using namespace std;

const double Eps = 1e-12;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

class Cmp
{
public:
	bool operator ()(double a, double b)
	{
		return sgn(a, b) < 0;
	}
};

const int N = 100011;
struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	double len() {
		return sqrt(x * x + y * y);
	}
}p[N];

double da[N], db[N];

int main()
{
	ios :: sync_with_stdio(false);
	Point a, b, t;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> t.x >> t.y;
	int n;
	cin >> n;
	multiset <double, Cmp> st;
	double sum = 0;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i].x >> p[i].y;
		da[i] = (p[i] - t).len() - (p[i] - a).len();
		db[i] = (p[i] - t).len() - (p[i] - b).len();
		st.insert(db[i]);
		sum += 2 * (t - p[i]).len();
	}
	if(n == 1)
	{
		cout << setprecision(12) << (t - p[0]).len() + 
			min((a - p[0]).len(), (b - p[0]).len()) << '\n';
		return 0;
	}

	double ans = 1e20;
	for(int i = 0; i < n; i ++)
	{
		st.erase(st.find(db[i]));
		ans = min(ans, sum - da[i] - *st.rbegin());
		ans = min(ans, sum - da[i]);
		st.insert(db[i]);
	}
	ans = min(ans, sum - *st.rbegin());
	cout << setprecision(12) << ans << '\n';
	return 0;
}