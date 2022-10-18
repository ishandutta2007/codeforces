#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

#define R(x) const { return x; }
template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) R(x<p.x || (x==p.x && y<p.y))
	bool operator==(P p) R(x==p.x && y==p.y)
	P operator+(P p) R(P(x+p.x, y+p.y))
	P operator-(P p) R(P(x-p.x, y-p.y))
	P operator*(T d) R(P(x*d, y*d))
	P operator/(T d) R(P(x/d, y/d))
	T dot(P p) R(x*p.x + y*p.y)
	T cross(P p) R(x*p.y - y*p.x)
	T dist2() R(x*x + y*y) // distance^2
	double dist() R(sqrt((double)dist2())) //length
	// angle to x-axis in interval [-pi, pi]
	double angle() R(atan2(y, x))
	P unit() R(*this/(T)dist()) // makes dist()=1
	P perp() R(P(-y, x)) // rotates +pi/2 radians
	P normal() R(perp().unit())
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) R(P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)))
};
typedef Point<ll> P;

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<P> p(N);
	rep(i,0,N)
		cin >> p[i].x >> p[i].y;
	int i1 = 0;
	P p1 = p[i1];
	pair<ll, int> dis(1LL << 62, -1);
	rep(i,1,N) {
		dis = min(dis, make_pair((p[i] - p1).dist2(), i));
	}
	int i2 = dis.second;
	P p2 = p[i2];

	pair<ll, int> dis2(1LL << 62, -1);
	rep(i,1,N) {
		if (i == i2) continue;
		ll ar = abs((p[i] - p1).cross(p[i] - p2));
		if (ar == 0) continue;
		dis2 = min(dis2, make_pair(ar, i));
	}

	int i3 = dis2.second;
	cout << i1+1 << ' ' << i2+1 << ' ' << i3+1 << endl;
}