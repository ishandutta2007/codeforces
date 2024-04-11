#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Vec {
	ll x, y;
	int index;
	Vec(ll x, ll y): x(x), y(y) {}

	Vec operator+(const Vec &o) const {
		return Vec(x+o.x, y+o.y);
	}

	Vec operator-(const Vec &o) const {
		return Vec(x-o.x, y-o.y);
	}

	ll operator*(const Vec &o) const {
		return x*o.x+y*o.y;
	}

	ll operator%(const Vec &o) const {
		return x*o.y-y*o.x;
	}

	void println() {
		cout<<"("<<x<<", "<<y<<")\n";
	}

	bool operator<(const Vec &o) const {
		if (x!=o.x) return x<o.x;
		return y<o.y;
	}

};

//checks if a left of b
bool leftOf(Vec a, Vec b, Vec pivot) {
	return (a-pivot)%(b-pivot)<0;
}

bool rightOf(Vec a, Vec b, Vec pivot) {
	return (a-pivot)%(b-pivot)>0;
}

int getIndexOfLeftmost(vector<Vec> points, Vec last) {
	int best=0;
	for (int i=1; i<points.size(); i++)
		if (leftOf(points[i], points[best], last))
			best=i;
	return best;
}

int getIndexOfRightmost(vector<Vec> points, Vec last) {
	int best=0;
	for (int i=1; i<points.size(); i++)
		if (rightOf(points[i], points[best], last))
			best=i;
	return best;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	vector<Vec> points;
	for (int i=0; i<n; i++) {
		int x, y; cin>>x>>y;
		points.push_back(Vec(x, y));
		points[i].index=i;
	}
	string targetMoves; cin>>targetMoves;
	vector<Vec> chosen;
	sort(points.begin(), points.end());

	Vec pivot=points[0];
	chosen.push_back(points[0]);
	points.erase(points.begin());

	for (int i=0; i<targetMoves.size(); i++) {
		int nextIndex;
		if (targetMoves[i]=='L') {
			nextIndex=getIndexOfRightmost(points, pivot);
		}
		else {
			nextIndex=getIndexOfLeftmost(points, pivot);
		}
		chosen.push_back(points[nextIndex]);
		pivot=points[nextIndex];
		points.erase(points.begin()+nextIndex);
	}
	chosen.push_back(points[0]);


	for (int i=0; i<n; i++) {
		cout<<chosen[i].index+1<<" \n"[i==n-1];
	}
	return 0;
}