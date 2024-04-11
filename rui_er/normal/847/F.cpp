// Problem: E. Berland Elections
// Contest: Codeforces - Training Round #1 (1400-1700-1900-2000-2100-2200, 120min)
// URL: https://codeforces.com/group/iw2l909Oqc/contest/396416/problem/E
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
const int N = 105;

int n, k, m, a, g[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Person {
	int vote, lst, id;
	Person(int a=0, int b=0, int c=0) : vote(a), lst(b), id(c) {}
	friend bool operator < (const Person& a, const Person& b) {
		if(a.vote != b.vote) return a.vote > b.vote;
		return a.lst < b.lst;
	}
}p[N], tmp[N];
bool check1(int id) {
	if(!p[id].vote) return 0;
	rep(i, 1, id-1) tmp[i] = p[i];
	rep(i, id+1, n) tmp[i-1] = p[i];
	sort(tmp+1, tmp+n);
	int rem = m - a, cnt = 0;
	rep(i, 1, n-1) {
		if(tmp[i] < p[id]) ++cnt;
		else {
			int diff = p[id].vote + 1 - tmp[i].vote;
			if(rem >= diff) {
				rem -= diff;
				++cnt;
			}
			else break;
		}
	}
	return cnt < k;
}
bool check3(int id) {
	rep(i, 1, id-1) tmp[i] = p[i];
	rep(i, id+1, n) tmp[i-1] = p[i];
	nth_element(tmp+1, tmp+k, tmp+n); // k-th
	int rem = m - a;
	if(Person(p[id].vote+rem, m) < tmp[k]) return 0;
	int diff = tmp[k].vote - p[id].vote;
	if(rem > diff) return 0;
	return 1;
}

int main() {
	scanf("%d%d%d%d", &n, &k, &m, &a);
	rep(i, 1, n) p[i].id = i;
	rep(i, 1, a) {
		scanf("%d", &g[i]);
		++p[g[i]].vote;
		p[g[i]].lst = i;
	}
	rep(i, 1, n) {
		if(check1(i)) printf("1%c", " \n"[i==n]);
		else if(check3(i)) printf("3%c", " \n"[i==n]);
		else printf("2%c", " \n"[i==n]);
	}
	return 0;
}