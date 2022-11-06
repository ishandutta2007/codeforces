// Problem: CF74A Room Leader
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF74A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 55;

int n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Person {
	string handle;
	int succ, fail, A, B, C, D, E;
	int score() {return 100 * succ - 50 * fail + A + B + C + D + E;}
	friend bool operator < (Person a, Person b) {return a.score() > b.score();}
}a[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		cin>>a[i].handle;
		scanf("%d%d%d%d%d%d%d", &a[i].succ, &a[i].fail, &a[i].A, &a[i].B, &a[i].C, &a[i].D, &a[i].E);
	}
	sort(a+1, a+1+n);
	puts(a[1].handle.c_str());
	return 0;
}