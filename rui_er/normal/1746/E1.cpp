// LUOGU_RID: 90659878
// Problem: E1. Joking (Easy Version)
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/E1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n;
vector<int> p, a, b, c, d, tmp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(vector<int>& a) {
	printf("? %d", (int)a.size());
	for(int i : a) printf(" %d", i);
	puts("");
	fflush(stdout);
	char s[5];
	scanf("%s", s);
	return s[0] == 'Y';
}
int give(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	char s[5];
	scanf("%s", s);
	return s[1] == ')';
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) p.push_back(i);
	while((int)p.size() >= 4) {
		int m = p.size();
		int cnt = m / 4, rem = m % 4;
		a.clear(); b.clear(); c.clear(); d.clear();
		rep(i, 0, cnt-1) a.push_back(p[i]);
		rep(i, cnt, 2*cnt-1) b.push_back(p[i]);
		rep(i, 2*cnt, 3*cnt-1) c.push_back(p[i]);
		rep(i, 3*cnt, 4*cnt-1) d.push_back(p[i]);
		if(rem) a.push_back(p[4*cnt]), --rem;
		if(rem) b.push_back(p[4*cnt+1]), --rem;
		if(rem) c.push_back(p[4*cnt+2]), --rem;
		tmp.clear();
		for(int i : a) tmp.push_back(i);
		for(int i : b) tmp.push_back(i);
		int x = ask(tmp);
		tmp.clear();
		for(int i : b) tmp.push_back(i);
		for(int i : c) tmp.push_back(i);
		int y = ask(tmp);
		p.clear();
		if(x && y) {
			for(int i : a) p.push_back(i);
			for(int i : b) p.push_back(i);
			for(int i : c) p.push_back(i);
		}
		else if(x && !y) {
			for(int i : a) p.push_back(i);
			for(int i : b) p.push_back(i);
			for(int i : d) p.push_back(i);
		}
		else if(!x && y) {
			for(int i : b) p.push_back(i);
			for(int i : c) p.push_back(i);
			for(int i : d) p.push_back(i);
		}
		else {
			for(int i : a) p.push_back(i);
			for(int i : c) p.push_back(i);
			for(int i : d) p.push_back(i);
		}
	}
	if((int)p.size() == 3) {
		a.clear(); b.clear();
		a.push_back(p[0]);
		b.push_back(p[0]);
		b.push_back(p[1]);
		int x = ask(a);
		int y = ask(b);
		int z = ask(b);
		int w = ask(a);
		tmp = p;
		p.clear();
		if(!x && y && z && !w) {
			p.push_back(tmp[0]);
			p.push_back(tmp[1]);
		}
		else {
			p.push_back(tmp[1]);
			p.push_back(tmp[2]);
		}
	}
	if((int)p.size() == 2) {
		if(!give(p[0])) {
			if(!give(p[1])) {
				assert(0);
			}
		}
	}
	if((int)p.size() == 1) {
		if(!give(p[0])) {
			assert(0);
		}
	}
	return 0;
}