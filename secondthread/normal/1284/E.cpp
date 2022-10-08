#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS=1e-6;
const ld PI=acos(-1.0);

template<typename T>
struct Vec {
	T x, y;
	int index;
	Vec(T x, T y): x(x), y(y) {}

	Vec<T> operator+(const Vec<T> &o) const {return Vec<T>(x+o.x, y+o.y);}
	Vec<T> operator-(const Vec<T> &o) const {return Vec<T>(x-o.x, y-o.y);}
	Vec<T> operator*(const T &o) const {return Vec<T>(x*o, y*o);}
	T operator*(const Vec<T> &o) const {return x*o.x+y*o.y;} // dot
	T operator%(const Vec<T> &o) const {return x*o.y-y*o.x;} // cross
	bool operator==(const Vec<T> &o) const{return x==o.x && y==o.y;}
	bool operator!=(const Vec<T> &o) const{return x!=o.x || y!=o.y;}
	Vec<T> operator-() const {return Vec<T>(-x, -y);}
	bool operator<(const Vec<T> &o) const {
		if (y!=o.y) return y<o.y;
		return x<o.x;
	}

	T mag2() const {return (*this)*(*this);}
	Vec<T> rot90() const {return Vec<T>(-y, x);}
	Vec<T> rot270() const{return Vec<T>(y, -x);}
	friend ostream& operator<<(ostream &cout, const Vec<T> &o) {
		cout<<"("<<o.x<<", "<<o.y<<")"; return cout;
	}

	//origin->q1, axes->the quadrant in ccw direction
	int quadrant() const {
		if (!x || !y) {
			if (!y) return x>=0?1:3;
			return y>=0?2:4;
		}
		if (x>0) return y>0?1:4;
		return y>0?2:3;
	}

	//can't handle (0, 0)
	bool radiallyLessThan(const Vec &o) const {
		if (quadrant()!=o.quadrant())
			return quadrant()<o.quadrant(); 
		return (*this)%o > 0; // Greater, be careful
	}

};

struct Pair {
	Vec<ll> *p1, *p2;
	Vec<ll> diff;
	Pair(Vec<ll> *p1, Vec<ll> *p2, Vec<ll> diff): p1(p1), p2(p2), diff(diff) {}

	bool operator<(Pair &o) const {
		return diff.radiallyLessThan(o.diff);
	}
};

ll choose3(ll n) {
	return n*(n-1)*(n-2)/(1*2*3);
}
ll choose4(ll n) {
	return n*(n-1)*(n-2)*(n-3)/(1*2*3*4);
}

//test these
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<Vec<ll>> points;
	for (int i=0; i<n; i++) {
		int x, y; cin>>x>>y;
		points.push_back(Vec<ll>(x, y));
	}
	sort(points.begin(), points.end());
	for (int i=0; i<n; i++) points[i].index = i;

	vector<Pair> pairs;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			pairs.emplace_back(&points[i], &points[j], points[j]-points[i]);
	sort(pairs.begin(), pairs.end());

	ll invalidSets=0;
	for (Pair &p:pairs) {
		Vec<ll> *p1=p.p1, *p2=p.p2;
		int ind1=p1->index, ind2=p2->index;
		swap(p1->index, p2->index);
		int nBelow=ind1, nAbove=n-ind2-1;
		ll toAdd=choose3(nBelow)+choose3(nAbove);
		invalidSets+=toAdd;
	}
	ll ans=choose4(n-1)*n-invalidSets;
	cout<<ans<<endl;
	return 0;
}