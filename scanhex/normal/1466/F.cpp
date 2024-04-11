#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N=500500;
vector<pair<int,int>>g[N];

int p[N];
bool good[N];
int getp(int x) {
	 return x == p[x] ? x : p[x] = getp(p[x]);
}
void un(int a, int b) {
	a = getp(a);
	b = getp(b);
	p[b] = a;
	good[a] |= good[b];
}

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int n, m; 
	 cin >> n >> m;
	 vector<int>roflan(m, -1);
	 vector<int>res;
	 vector<array<int,3>>ed;
	 for(int i=0;i<n;++i) {
		 int k;
		 cin >> k;
		 if (k == 1)
		 {
			 int x;
			 cin >> x;
			 --x;
			 ed.push_back({x, x, i});
		 }
		 else {
			 int x, y ;
			 cin >> x >> y; 
			 --x, --y;
			 ed.push_back({x, y, i});
			 g[x].emplace_back(y,i);
			 g[y].emplace_back(x,i);
		 }
	 }
	 iota(p, p + N, 0);
	 for(auto x : ed) { 
		 if (x[0] == x[1]) {
			 if (good[getp(x[0])])
				 continue;
			 good[getp(x[0])] = true;
			 res.push_back(x[2]);
		 }
		 else {
		 if (getp(x[0]) == getp(x[1]) || good[getp(x[0])] && good[getp(x[1])])
			 continue;
		 un(x[0], x[1]);
		 res.push_back(x[2]);
	 }
	 }
	 vector<int>res1;
	 for(auto&x : res)
		 if (good[getp(ed[x][0])]) {
			 res1.push_back(x);
		 }
	 const int mod=1e9+7;
	 int ans=1;
	 for(int i=0;i<res.size();++i)
		 ans *=2, ans %= mod;
	 cout << ans << ' ' << res.size() << '\n';
	 for(int x : res)
		 cout << x + 1 << ' ';
	 cout << '\n';

	 /*
	 vector<int>prev(m, -1);
	 vector<int>num(m);
	 vector<int>q;
	 for(int i=0;i<m;++i) 
		 if (roflan[i] != -1) {
			 prev[i] = -2;
			 num[i] = roflan[i];
			 q.push_back(i);
		 }
	 for(int i=0;i<q.size();++i) {
		  int x = q[i];
			for(auto [y,nm] : g[x]) {
				if (prev[y] == -1) 
					prev[y] = x, num[y]=nm, q.push_back(y);
			}
	 }
	 int ans=1;
	 set<int>ansi;
	 for(int x = 0; x < m; ++x) 
		 if (prev[x] != -1) {
			 ans *= 2, ans %= mod;
			 int kek = 0;
			 int y = x;
			 while(y != -2) {
				 if (ansi.count(num[y]))
					 break;
				 ansi.insert(num[y]);
				 y = prev[y];
			 }
		 }
	 cout << ans << ' ' << ansi.size() << '\n';
	 for(int x :ansi)
		 cout << x + 1 << ' ';
	 cout << '\n';
	 */
	 return 0;
}