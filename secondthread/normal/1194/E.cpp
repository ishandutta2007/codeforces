#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct BIT {
	const int n;
	int *arr;
	BIT(int n): n(n), arr(new int[n+2]()){}
	~BIT(void) {delete [] arr;}
	void add(int i, int v) {
		for (int j=i; j<=n; j+=(j&-j)) arr[j]+=v;
	}

	int query(int hi) {
		int ret=0;
		for (int j=hi; j>0; j-= (j&-j)) ret+=arr[j];
		return ret;
	}

};

struct Seg {
	int x1, y1, x2, y2;
	Seg(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
	bool vert() const {return x1==x2;}

	bool operator<(const Seg &o) const {
		if (y2==o.y2)
			if (vert()==o.vert()) return false;
			else return !vert();
		return y2<o.y2;
	}
	//assumes I am hor.
	bool intersects(const Seg &o) {
		if (o.y1>y1||o.y2<y1||x1>o.x1||x2<o.x2)
			return false;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<Seg> segs;
	for (int i=0; i<n; i++) {
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
		if (x1>x2) swap(x1, x2);
		if (y1>y2) swap(y1, y2);
		Seg s(x1, y1, x2, y2);
		segs.push_back(s);
	}
	sort(segs.begin(), segs.end());
	ll ans=0;
	for (int lowerInd=0; lowerInd<n; lowerInd++) {
		if (segs[lowerInd].vert()) continue;
		BIT bit(10002);
		int offset=5001;
		Seg lower=segs[lowerInd];
		for (int oInd=n-1; oInd>lowerInd; oInd--) {
			Seg other=segs[oInd];
			if (other.vert() && lower.intersects(other))
				bit.add(other.x1+offset, 1);
			if (!other.vert()) {
				int intWith=bit.query(other.x2+offset)-bit.query(other.x1+offset-1);
				ans+=(intWith)*(ll)(intWith-1)/2;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}