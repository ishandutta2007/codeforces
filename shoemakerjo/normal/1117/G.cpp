#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 1000010;
#define pii pair<int, int>
#define pp pair<pii, int>
#define mp make_pair
#define pll pair<ll, ll>
int n, q;

int fafter[maxn];
int fbefore[maxn];
int nums[maxn];
int li[maxn], ri[maxn];

ll seg[maxn*4];

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}  

void upd(int spot, ll val, int ss = 1, int se = n, int si = 0) {

	seg[si] += val;
	if (ss == se) return;

	int mid = (ss+se)/2;
	if (spot <= mid) {
		upd(spot, val, ss, mid, si*2+1);
	}
	else upd(spot, val, mid+1, se, si*2+2);
}

ll segq(int qs, int qe, int ss = 1, int se = n, int si = 0) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;

	if (qs <=  ss && se <= qe) return seg[si];

	int mid = (ss+se)/2;
	return segq(qs, qe, ss, mid, si*2+1) + 
		segq(qs, qe, mid+1, se, si*2+2);
}
ll ans[maxn];

ll BIT[2][maxn];


ll bq(int indo, int spot) {
	ll res = 0;
	while (spot > 0) {
		res += BIT[indo][spot];
		spot -= spot & (-spot);
	}
	return res;
}

void bup(int indo, int spot, ll val) {

	// if (indo == 0) cout << "sp: " << spot << endl;
	while (spot <= n) {
		BIT[indo][spot] += val;
		spot += spot & (-spot);
	}
}


vector<int> sts[maxn];
vector<int> sremo[maxn];
vector<int> ens[maxn];
vector<int> eremo[maxn];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> li[i];
	}
	for (int j = 1; j <= q; j++) {
		cin >> ri[j];
	}

	stack<pii> vals;
	vals.push(pii(n+1, 0));

	for (int i = 1; i <= n; i++) {
		while (nums[i] > vals.top().first) vals.pop();
		fbefore[i] = vals.top().second;

		vals.push(pii(nums[i], i));
	}
	while (vals.size()) vals.pop();

	vals.push(pii(n+1, n+1));
	for (int i =  n; i >= 1; i--) {
		while (nums[i] > vals.top().first) vals.pop();
		fafter[i] = vals.top().second;

		vals.push(pii(nums[i], i));
	}


	for (int i = 1; i <= n; i++) {

		// cout << "range of " << i << " : " << fbefore[i]+1 << 
		// 	" " << fafter[i]-1 << endl
		
		ens[i].push_back(fbefore[i]+1);
		eremo[fbefore[i]+1].push_back(i);
		sts[i].push_back(fafter[i]-1);
		sremo[fafter[i]-1].push_back(i);

		upd(i, fafter[i] - fbefore[i] - 1);

	}

	vector<pp> stuff;

	int a, b;
	for (int i = 1; i <= q; i++) {
		a = li[i];
		b = ri[i];
		
		ans[i] = segq(a, b);


		// cout << a << ":" << b << " pre answer: " << ans[i] << endl;

		stuff.push_back(mp(mp(a, b), i));

	}

	sort(stuff.begin(), stuff.end(),
		[](const pp & a, const pp & b) -> bool
		{
			if (a.first.second == b.first.second) {
				if (a.first.first == b.first.first) 
					return a.second < b.second;
				return a.first < b.first;
			}
			return a.first.second < b.first.second;
		});

	int indo;

	int pb = 0;

	for (pp vp : stuff) {
		a = vp.first.first;
		b = vp.first.second;
		indo = vp.second;
		for (int i = pb+1; i <= b; i++) {
			for (int v : sts[i]) {

				// cout << "		add end of " << v << endl;
				bup(0, i, v);
				bup(1, i, 1);
			}
			for (int v : sremo[i]) {

				// cout << "		remove end of " << i << endl;
				bup(1, v, -1);
				bup(0, v, 0-i);
			}
		}

		pb = b;

		ll ct = bq(1, n) - bq(1, a-1);

		ll csum = bq(0, n) - bq(0, a-1);

		// cout << "   " << a << ":" << b << " : " << ct << ", " << csum << endl;

		ans[indo] -= csum - ct * b;

	}

	fill(BIT[0], BIT[0]+maxn, 0LL);
	fill(BIT[1], BIT[1]+maxn, 0LL);

	sort(stuff.begin(), stuff.end());
	reverse(stuff.begin(), stuff.end());

	pb = n+1;

	// cout << endl << endl;

	for (pp vp : stuff) {
		a = vp.first.first;
		b = vp.first.second;
		indo = vp.second;
		for (int i = pb-1; i >= a; i--) {
			for (int v : ens[i]) {
				bup(0, i, v);
				bup(1, i, 1);
			}
			for (int v : eremo[i]) {
				bup(1, v, -1);
				bup(0, v, 0-i);
			}
		}
		pb = a;

		ll ct = bq(1, b);
		ll csum = bq(0, b);

		// cout << "   " << a << ":" << b << " : " << ct << ", " << csum << endl;

		ans[indo] -= ct * a - csum;

	}

	for (int i = 1; i <= q; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

}