#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}
int nn=0;

struct point{
	int x, y, z, id;
	void input() {
		scanf("%d %d %d", &x, &y, &z);
		id = ++nn;
	}
};

const int NN = 100011;
vector<point> vec;
map<pii, vector<point> > mp[3];
int flag[NN];
using vp = vector<point>;
int rr;

void disp(int u, int v) {
	printf("%d %d\n", u, v);
	flag[u] = flag[v] = 1;
}
int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		point p;
		p.input();
		vec.pb(p);
		mp[0][{p.x, p.y}].pb(p);
		mp[1][{p.x, p.z}].pb(p);
		mp[2][{p.y, p.z}].pb(p);
	}
	for(int i=0; i<3; i++) {
		for(auto it = mp[i].begin(); it != mp[i].end(); it++) {
			vector<point> now = it->y;
			rr= i;
			int pre = -1;
			sort(now.begin(), now.end(), [](point u, point v) {
				if(rr==2) return u.x<v.x;
				if(rr==1) return u.y<v.y;
				return u.z<v.z;
			});
			for(auto u : now) {
				if(flag[u.id]) continue;
				if(pre==-1) pre = u.id;
				else disp(pre, u.id), pre=-1;
			}
		}
	}
	map<int, vp> mp[3];
	for(auto p : vec) if(flag[p.id] == 0) {
		mp[0][p.x].pb(p);
		mp[1][p.y].pb(p);
		mp[2][p.z].pb(p);
	}
	for(int i=0; i<3; i++) {
		for(auto it = mp[i].begin(); it != mp[i].end(); it++) {
			vector<point> now = it->y;
			rr= i;
			int pre = -1;
			sort(now.begin(), now.end(), [](point u, point v) {
				if(rr==2) return u.x == v.x ? u.y < v.y : u.x<v.x;
				if(rr==1) return u.x == v.x ? u.z < v.z : u.x < v.x;
				return u.y == v.y ? u.z < v.z : u.y < v.y;
			});
			for(auto u : now) {
				if(flag[u.id]) continue;
				if(pre==-1) pre = u.id;
				else disp(pre, u.id), pre=-1;
			}
		}
	}
	sort(vec.begin(), vec.end(), [](point u, point v) {
		if(u.x != v.x) return u.x < v.x;
		if(u.y != v.y) return u.y < v.y;
		return u.z < v.z;
		});
	int pre = -1;
	for(auto u : vec) {
				if(flag[u.id]) continue;
				if(pre==-1) pre = u.id;
				else disp(pre, u.id), pre=-1;
			}
	return 0;
}