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
#define N 211111
using namespace std;
typedef pair<int,int> pt;

struct ft{
	int n;
	vector<int> s;
	ft(int g) {
		n = g;
		s.clear();
		for (int i = 0; i <= n; i++) s.pb(0);			
	}	

	void add(int x, int v) {
		x++;
		while (x <= n) {
			s[x] += v;
			x = x + x - (x & (x - 1));
		}
	}
	int fin(int x) {
		x++;
		int r = 0;
		while (x > 0) {
			r += s[x];
			x &= x - 1;
		}
		return r;
	}
};

int solve(vector<pt> a) {
	vector<pt> b = a;
	for (int i = 0; i < b.size(); i++) swap(b[i].F, b[i].S);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int n = a.size();

	set<pt> aa, bb;
	set<pt>::iterator it;

	for (int i = 0; i < n; i++) aa.insert(a[i]);
	for (int i = 0; i < n; i++) bb.insert(b[i]);

	ft A = ft(n);
	ft B = ft(n);

	for (int i = 0; i < n; i++) {
		A.add(i, 1);
		B.add(i, 1);
	}
	vector<pair<int, int> > ev;
	for (int i = 1; i < n; i++) if (a[i].F > a[i - 1].F + 1) ev.pb(mp(a[i].F - 1, 1));

	for (int i = 1; i < n; i++) if (b[i].F > b[i - 1].F + 1) ev.pb(mp(b[i].F - 1, 2));

	int ret = 1;
	int cur = 0;
	int sz = n;

	while (cur < ev.size()) {
		int x = ev[cur].F;
		int type = ev[cur].S;
		cur++;
		vector<pt> rem;

		if (type == 1) {
			int u = lower_bound(a.begin(), a.end(), mp(x, (int)1e9+ 1)) - a.begin() - 1;
			int t = A.fin(u);

			it = aa.lower_bound(mp(x, (int)-1e9 - 1));
			if (it != aa.end() && (*it).F == x) t = 0;

			if (t == 0 || t == sz) {
				//n
			} else
			if (t + t < sz) {
				//remove prefix
				for (it = aa.begin(); it != aa.end(); it++) {
					if ((*it).F > x) break;
					rem.pb(*it);						 	
				}
					
			} else {
				//remove suffix
				it = aa.end();
				it--;
				for(;;) {
					if ((*it).F < x) break;
					rem.pb(*it);
					if (it == aa.begin()) break;
					it--;
				}
			}
		} else {
			int u = lower_bound(b.begin(), b.end(), mp(x, (int)1e9+ 1)) - b.begin() - 1;
		
			int t = B.fin(u);
			pt temp;

			it = bb.lower_bound(mp(x, (int)-1e9 - 1));
			if (it != bb.end() && (*it).F == x) t = 0;
			

			if (t == 0 || t == sz){
				//n
			} else
			if (t + t < sz) {
				//remove prefix
				for (it = bb.begin(); it != bb.end(); it++) {
					if ((*it).F > x) break;
					temp = *it;
					swap(temp.F, temp.S);
					rem.pb(temp);						 	
				}
					
			} else {
				//remove suffix
				it = bb.end();
				it--;
				for(;;) {
					if ((*it).F < x) break;
					temp = *it;
					swap(temp.F, temp.S);
					rem.pb(temp);						 	
					if (it == bb.begin()) break;
					it--;
				}
			}

		}
		if (rem.size() > 0) {
//		cout << "! " << rem.size() << endl;

		for (int i = 0; i < rem.size(); i++) {
			ev.pb(mp(rem[i].F, 1));
			ev.pb(mp(rem[i].S, 2));

			pt temp = rem[i];

			aa.erase(temp);
			int u = lower_bound(a.begin(), a.end(), temp) - a.begin();
			A.add(u, -1);

			swap(temp.F, temp.S);

			bb.erase(temp);
			u = lower_bound(b.begin(), b.end(), temp) - b.begin();
			B.add(u, -1);
			
		}
		sz -= rem.size();
		ret += solve(rem);
		}

	}
//	for (int i = 0; i < a.size(); i++) cout << a[i].F << " " << a[i].S << endl;
//	cout << ret << endl;
	return ret;

}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int n;
	cin >> n;
	vector<pt> a;
	a.resize(n);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i].F, &a[i].S);
	cout << solve(a) << endl;
	return 0;
}