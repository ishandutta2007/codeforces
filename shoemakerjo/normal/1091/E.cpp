#include <bits/stdc++.h>

using namespace std;
#define maxn 500010
#define ll long long
int n;

vector<int> deg;
const ll inf = 1LL << 31;

ll seg[maxn*4]; //min segment tree i think
ll seg2[maxn*4];

ll ovals[maxn]; //start to segtree

const bool debug = false;

void buildtree(int ss = 1, int se = n, int si = 0) {
	if (ss == se) {
		if (debug) {
			cout << "oval for " << ss << " is " << ovals[ss] << endl;
		}
		seg[si] = ovals[ss];
		seg2[si] = ovals[ss] + ss;
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	seg[si] = min(seg[si*2+1], seg[si*2+2]);
	seg2[si] = min(seg2[si*2+1], seg2[si*2+2]);
}

ll query(int qs, int qe, int ss = 1, int se = n, int si = 0) {
	if (qs > qe || ss > se || qs > se || qe < ss) return inf;

	if (qs <= ss && se <= qe) return seg[si];

	int mid = (ss+se)/2;
	return min(query(qs, qe, ss, mid, si*2+1),
		query(qs, qe, mid+1, se, si*2+2));
}

ll query2(int qs, int qe, int ss = 1, int se = n, int si = 0) {
	if (qs > qe || ss > se || qs > se || qe < ss) return inf;

	if (qs <= ss && se <= qe) return seg2[si];

	int mid = (ss+se)/2;
	return min(query2(qs, qe, ss, mid, si*2+1),
		query2(qs, qe, mid+1, se, si*2+2));
}

void update(int spot, ll val, int ss = 1, int se = n, int si = 0) {
	if (ss > se || spot > se || spot < ss) return;

	if (ss == se) {
		seg[si] = val;
		seg2[si] = val + spot;
		return;
	}

	int mid = (ss+se)/2;
	if (spot <= mid) {
		update(spot, val, ss, mid, si*2+1);
	}
	else update(spot, val, mid+1, se, si*2+2);

	seg[si] = min(seg[si*2+1], seg[si*2+2]);
	seg2[si] = min(seg2[si*2+1], seg2[si*2+2]);
}

ll sumbef[maxn];
ll incval[maxn];
vector<int> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cur;
	ll sum = 0LL;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		deg.push_back(cur);
		sum += cur;
	}
	deg.push_back(maxn);
	sort(deg.begin(), deg.end());
	reverse(deg.begin(), deg.end());
	//we have a buffer at the start to 1-index it

	sumbef[1] = 0LL;
	for (int i = 2; i<= n+1; i++) {
		sumbef[i] = sumbef[i-1] + deg[i-1];
	}

	for (int i = 1; i <= n; i++) {
		ovals[i] = i*1LL*(i-1);
	}
	ll sub = 0LL;
	for (int i = 1; i <= n; i++) {
		sub += deg[i];
		ovals[i] -= sub;
	}

	ll inc = 0LL;
	int numk = 0;
	priority_queue<int> pq;
	for (int i = n; i >= 1; i--) {
		inc -= numk;
		while (pq.size() && pq.top() > i) {
			numk++;
			inc += i - pq.top();
			pq.pop();
		}
		ovals[i] += inc;
		incval[i] = numk;
		pq.push(deg[i]);
		inc += deg[i];
	}

	buildtree();

	inc = 0LL;
	numk = 0;
	while (pq.size()) pq.pop();

	int spot = n+1;
	for (int val = 0; val <= n; val++) {
		//check if this val works
		int nspot = spot;
		while (nspot > 0 && deg[nspot-1] < val) nspot--;

		for (int i = spot-1; i >= nspot; i--) {
			//this guy's k*(k-1) changes
			ll nv = ovals[i];
			nv -= i*1LL*(i-1LL);
			nv += i*1LL*(i+1LL);
			nv += incval[i]+0LL;
			//this guy's before sum and after sum also change
			update(i, nv);
			if (debug) cout << "new val for " << i << "(" << deg[i] << ")" << " :: " << nv << endl;

			pq.push(deg[i]);
			inc += deg[i];
			//easy to calculate min for everything after me
		}

		inc -= numk * 1LL * (spot - nspot);
		while (pq.size() && pq.top() >= nspot) {
			numk++;
			inc += nspot - pq.top();
			pq.pop();
		} 

		bool ok = true;
		if ((sum+val)%2 != 0) {
			ok = false;
		}
		else {


			ll minaft = query(nspot, n);
			if (debug) cout << val  << " min aft:  " << minaft << endl;
			minaft -= val;
			if (minaft < 0) ok = false;

			if (debug && val == 21) cout << "MA: " << minaft << endl;

			else {
				//do the other query
				ll mv = query(val, nspot-1);
				mv += val;
				// if (debug) cout << val << " :: " << mv << endl;
				if (mv < 0) ok = false;

				// if (ok) cout << val << " is still alive " << endl;
				mv = query2(1, min(val, nspot-1));
				if (mv < 0) ok = false;

			}
		}
		if (ok) {
			//now calculate my value
			ll cv = nspot*1LL*(nspot-1LL);
			cv -= sumbef[nspot];
			cv -= val;
			cv += inc;
			if (debug) cout << val << "  cv:  " << cv << endl;
			if (cv < 0) ok = false;

		}

		if (debug) cout << val << " : " << spot << endl;

		if (ok) ans.push_back(val);
		spot = nspot;
	}

	if (ans.size()) {
		for (int v : ans) cout << v << " ";
		cout << endl;
	}

	else cout << -1 << endl;
}