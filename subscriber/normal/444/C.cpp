#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 411111
using namespace std;
typedef pair<int,int> pt;

int n, m;
long long sum[N], add[N];
set<pair<pt, int> > W;
set<pair<pt, int> > :: iterator it;

void mod(int pos, int l, int r, int ll, int rr, long long v) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return;
	if (l == ll && r == rr) {
		sum[pos] += (r - l + 1) * v;
		add[pos] += v;
		return;
	}
	if (add[pos] != 0) {
		mod(pos + pos, l, (l + r) / 2, l, r, add[pos]);
		mod(pos + pos + 1, (l + r) / 2 + 1, r, l, r, add[pos]);
		add[pos] = 0;
	}
	mod(pos + pos, l, (l + r) / 2, ll, rr, v);
	mod(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr, v);
	sum[pos] = sum[pos + pos] + sum[pos + pos + 1];
}

long long fin(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return 0;
	if (l == ll && r == rr) return sum[pos];
	if (add[pos] != 0) {
		mod(pos + pos, l, (l + r) / 2, l, r, add[pos]);
		mod(pos + pos + 1, (l + r) / 2 + 1, r, l, r, add[pos]);
		add[pos] = 0;
	}
	long long q1 = fin(pos + pos, l, (l + r) / 2, ll, rr);
	long long q2 = fin(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr);
	return q1 + q2;
}

void di(int x) {
	it = W.lower_bound(mp(mp(x + 1, x), 0));
	if (it == W.begin()) return;
	it--;
	int ll = (*it).F.F;
	int rr = (*it).F.S;
	int col = (*it).S;
	if (x >= ll && x < rr) {
		W.erase(it);
		W.insert(mp(mp(ll, x), col));
		W.insert(mp(mp(x + 1, rr), col));		
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) W.insert(mp(mp(i, i), i));
	while (m--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--;
			r--;
			x--;
			di(l - 1);
			di(r);
			for(;;) {

				it = W.lower_bound(mp(mp(l, l), 0));
				if (it == W.end() || (*it).F.F > r) break;

				int dif = abs(x - (*it).S);
				mod(1, 0, n - 1, (*it).F.F, (*it).F.S, dif);
				W.erase(it);
			}
			W.insert(mp(mp(l, r), x));
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			r--;
			printf("%I64d\n", fin(1, 0, n - 1, l, r)); 
		}
	}
	return 0;
}