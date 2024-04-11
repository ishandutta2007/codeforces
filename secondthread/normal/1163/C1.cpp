#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b==0) return abs(a);
	return gcd(b, a%b);
}

bool eq(ld a, ld b) {
	return abs(a-b)<1e-9;
}

struct Frac {
	ll n, d;
	Frac(ll a, ll b) {
		assert(b!=0);
		if (a==0) {
			d=1;
			n=0;
			return;
		}
		ll g=gcd(a, b);
		n=a/g;
		d=b/g;
		if (d<0) {
			n*=-1;
			d*=-1;
		}
	}

	Frac operator+(Frac o) {
		return Frac(n*o.d+o.n*d, d*o.d);
	}

	Frac operator-(const Frac o) const{
		return Frac(n*o.d-d*o.n, d*o.d);
	}

	Frac operator *(Frac o) {
		return Frac(n*o.n, d*o.d);
	}

	Frac inv() {
		return Frac(d, n);
	}

	Frac operator/(Frac o) {
		return (*this)*(o.inv());
	}

	bool operator<(const Frac &o) const {
		return n*o.d-d*o.n<0;
	}

	bool operator==(const Frac &o) const {
		return n==o.n&&d==o.d;
	}

	bool operator !=(const Frac &o) const {
		return !operator==(o);
	}

	string toString() const{
		stringstream ss;
		ss<<n<<"/"<<d;
		return ss.str();
	}
};

struct Vec {
	Frac x, y;
	Vec (Frac x, Frac y): x(x), y(y){}

	Vec operator+(Vec o) {
		return Vec(x+o.x, y+o.y);
	}

	Vec operator-(Vec o) {
		return Vec(x-o.x, y-o.y);
	}
	
	Frac operator*(Vec o) {
		return x*o.x+y*o.y;
	}

	Frac operator%(Vec o) {
		return x*o.y-y*o.x;
	}


	bool operator<(const Vec &o) const{
		//cout<<" Comparing "<<toString()<<" to "<<o.toString()<<endl;
		if (x!=o.x)
			return (x-o.x).n<0;
		return (y-o.y).n<0;
	}

	string toString() const{
		stringstream ss;
		ss<<"("<<x.toString()<<", "<<y.toString()<<")";
		return ss.str();
	}

};


struct Line {
	Frac m, b;
	Line(Vec a, Vec bb):m(1, 1), b(1, 1) {
		if (a.x==bb.x) {
			m=Frac(1000000000, 1);
			b=Frac(a.x.n, 1);
		}
		else {
			Vec d=bb-a;
			m=d.y/d.x;
			b=a.y-m*a.x;
		}
	}

	ll operator <(const Line o) const {
		if (m!=o.m) return m<o.m;
		if (b!=o.b) return b<o.b;
		return 0;
	}

	string toString() const{ 
		stringstream ss;
		ss<<"y = "<<m.toString()<<"*x + "<<b.toString();
		return ss.str();
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<Vec> points;
	////cout<<"Initializing points"<<endl;
	for (int i=0; i<n; i++) {
		ll x, y;
		cin>>x>>y;
		Vec temp(Frac(x, 1), Frac(y, 1));
		points.push_back(temp);
	}
	//cout<<"Points: "<<endl;
	for (int i=0; i<points.size(); i++) {
		//cout<<points[i].toString()<<endl;
	}
	//cout<<"Done initializing..."<<endl;
	sort(points.begin(), points.end());
	//cout<<"Sorted"<<endl;

	map<Frac, int> slopesSeen;
	set<Line> linesSeen;
	int linesTotal=0;
	ll ans=0;
	for (int startInd=0; startInd<n; startInd++) {
		for (int lastInd=0; lastInd<n; lastInd++) {
			if (startInd==lastInd) continue;
			//cout<<"\tTrying startInd: "<<startInd<<" lastInd: "<<lastInd<<endl;
			Line cand(points[startInd], points[lastInd]);
			//cout<<"\tcand: "<<cand.toString()<<endl;
			if (linesSeen.count(cand)!=0) { 
				//cout<<"Already seen this line...\n";
				continue;
			}
			auto it=slopesSeen.find(cand.m);
			if (it==slopesSeen.end()) {
				ans+=linesTotal;
				slopesSeen[cand.m]=1;
			}
			else {
				ans+=linesTotal-(*it).second;
				slopesSeen[cand.m]++;
			}
			linesTotal++;
			linesSeen.insert(cand);
		}
	}

	cout<<ans<<endl;

	return 0;
}