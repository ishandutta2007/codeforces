//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105; 

int n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
vector<int> nega, posi, zero, x, y, z;
void print(const vector<int> &p) {
	int sz = p.size();
	printf("%d ", sz);
	rep(i, 0, sz-1) printf("%d%c", p[i], " \n"[i==sz-1]);
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i] > 0) posi.push_back(a[i]);
		else if(a[i] < 0) nega.push_back(a[i]);
		else zero.push_back(a[i]);
	}
	if(posi.size()) {
		y.push_back(posi[0]);
		x.push_back(nega[0]);
		int sz = 0;
		sz = nega.size(); rep(i, 1, sz-1) z.push_back(nega[i]);
		sz = posi.size(); rep(i, 1, sz-1) z.push_back(posi[i]);
		sz = zero.size(); rep(i, 0, sz-1) z.push_back(zero[i]);
	}
	else {
		y.push_back(nega[0]);
		y.push_back(nega[1]);
		x.push_back(nega[2]);
		int sz = 0;
		sz = nega.size(); rep(i, 3, sz-1) z.push_back(nega[i]);
		sz = zero.size(); rep(i, 0, sz-1) z.push_back(zero[i]);
	}
	print(x); print(y); print(z);
	return 0;
}