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
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, q;
int a[N];

vector<pair<int, int> > bs[888000];
int ad[888000];

vector<pair<int, int> > un(vector<pair<int, int> > & a, vector<pair<int, int> > & b) {
	vector<pair<int, int> > c;
	for (int i = 0; i < a.size(); i++) c.pb(a[i]);
	for (int i = 0; i < b.size(); i++) c.pb(b[i]);

/*	cout << "I" << endl;
	for (int i = 0; i < a.size(); i++) cout << a[i].F << " ";
	cout << endl;
	for (int i = 0; i < b.size(); i++) cout << b[i].F << " ";
	cout << endl;                    */

	for (int i = 0; i < c.size(); i++) {
		int id = i;
		for (int j = i + 1; j < c.size(); j++) if (c[j].F > c[id].F) id = j;
		swap(c[i], c[id]);
		if (c[i].F == 0) break;

		for (int j = i + 1; j < c.size(); j++) if ((c[j].F & c[i].F) * 2 > c[i].F) {
//			cout << "! " << c[i].F << " " << c[j].F << endl;
			
			c[j].F ^= c[i].F;
			c[j].S ^= c[i].S;
		}			
	}
	int nz = 0;
	for (int i = 0; i < c.size(); i++) if (c[i] == mp(0, 1)) nz = 1;
	while (c.size() > 0 && c.back().F == 0) c.pop_back();
	if (nz) c.pb(mp(0, 1));

/*	for (int i = 0; i < c.size(); i++) cout << c[i].F << " ";
	cout << endl;
	cout << "O " << endl;*/
	
	return c;
}

vector<pair<int, int> > sim(vector<pair<int, int> > & a) {
	vector<pair<int, int> > c;
	for (int i = 0; i < a.size(); i++) c.pb(a[i]);

	for (int i = 0; i < c.size(); i++) {
		int id = i;
		for (int j = i + 1; j < c.size(); j++) if (c[j].F > c[id].F) id = j;
		swap(c[i], c[id]);
		if (c[i].F == 0) break;

		for (int j = i + 1; j < c.size(); j++) if ((c[j].F & c[i].F) * 2 > c[i].F) {
//			cout << "! " << c[i].F << " " << c[j].F << endl;
			c[j].F ^= c[i].F;
			c[j].S ^= c[i].S;
		}			
	}
	int nz = 0;
	for (int i = 0; i < c.size(); i++) if (c[i] == mp(0, 1)) nz = 1;
	while (c.size() > 0 && c.back().F == 0) c.pop_back();
	if (nz) c.pb(mp(0, 1));
	return c;
}


void init(int pos, int l, int r) {
	if (l == r) {
		bs[pos].pb(mp(a[l], 1));
		return;
	}
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);

	bs[pos] = un(bs[pos + pos], bs[pos + pos + 1]);
}

void mod(int pos, int l, int r, int ll, int rr, int k) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return;
	if (l == ll && r == rr) {
		ad[pos] ^= k;
		for (int i = 0; i < bs[pos].size(); i++) if (bs[pos][i].S) bs[pos][i].F ^= k;
		return;
	}
	if (ad[pos] != 0) {
		ad[pos + pos] ^= ad[pos];
		for (int i = 0; i < bs[pos + pos].size(); i++) if (bs[pos + pos][i].S) bs[pos + pos][i].F ^= ad[pos];
		ad[pos + pos + 1] ^= ad[pos];
		for (int i = 0; i < bs[pos + pos + 1].size(); i++) if (bs[pos + pos + 1][i].S) bs[pos + pos + 1][i].F ^= ad[pos];

		ad[pos] = 0;
	}
	mod(pos + pos, l, (l + r) / 2, ll, rr, k);
	mod(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr, k);
	bs[pos] = un(bs[pos + pos], bs[pos + pos + 1]);
}


vector<pair<int, int> > zer;


vector<pair<int, int> > get(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return zer;
	if (l == ll && r == rr) return sim(bs[pos]);

	if (ad[pos] != 0) {
		ad[pos + pos] ^= ad[pos];
		for (int i = 0; i < bs[pos + pos].size(); i++) if (bs[pos + pos][i].S) bs[pos + pos][i].F ^= ad[pos];
		ad[pos + pos + 1] ^= ad[pos];
		for (int i = 0; i < bs[pos + pos + 1].size(); i++) if (bs[pos + pos + 1][i].S) bs[pos + pos + 1][i].F ^= ad[pos];

		ad[pos] = 0;
	}
	

	vector<pair<int ,int> > v1 = get(pos + pos, l, (l + r) / 2, ll, rr);
	vector<pair<int ,int> > v2 = get(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr);

//	bs[pos] = un(bs[pos + pos], bs[pos + pos + 1]);
	

	return un(v1, v2);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	init(1, 0, n - 1);
	for (int i = 0; i < q; i++) {
		
		int ty, x, y, k;
		scanf("%d%d%d", &ty, &x, &y);
		x--;
		y--;
		if (ty == 2) {
			vector<pair<int, int> > bs = get(1, 0, n - 1, x, y);
			int sz = 0;
			for (int i = 0; i < bs.size(); i++) if (bs[i].F) sz++;
//			for (int j = 0; j < bs.size(); j++) cout << bs[j].F << " " << bs[j].S << endl;
			printf("%I64d\n", pw(sz));
		} else {
			scanf("%d", &k);
			mod(1, 0, n - 1, x, y, k);
		}
	}
	return 0;
}