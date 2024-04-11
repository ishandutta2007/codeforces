//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 4e6 + 9;
char s[Maxn];
int sc[Maxn],fc[Maxn],t[Maxn][2],is[Maxn],n;
void prop(int v,int l,int r) {
	is[l] ^= 1;
	is[r] ^= 1;
	is[v] = 0;
	swap(sc[r],fc[r]);
	swap(sc[l],fc[l]);
	swap(t[l][0],t[l][1]);
	swap(t[r][0],t[r][1]);
	return;
}
void build(int v = 1,int b = 0,int e = n-1) {
	if(b == e) {
		sc[v] = (s[b] == '7');
		fc[v] = (s[b] == '4');
		for(int c = 0; c < 2;c++) t[v][c] = 1;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	build(l,b,mid);
	build(r,mid+1,e);
	sc[v] = sc[l] + sc[r];
	fc[v] = fc[l] + fc[r];
	t[v][0] = max(fc[l] + t[r][0],t[l][0] + sc[r]);
	t[v][1] = max(sc[l] + t[r][1],t[l][1] + fc[r]);
	return;
}
void update(int i,int j,int v = 1,int b = 0,int e = n-1) {
	if(i > e || b > j) return;
	if(i <= b && e <= j) {
		swap(sc[v],fc[v]);
		swap(t[v][0],t[v][1]);
		is[v] ^= 1;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	if(is[v]) prop(v,l,r);
	update(i,j,l,b,mid);
	update(i,j,r,mid+1,e);
	sc[v] = sc[l] + sc[r];
	fc[v] = fc[l] + fc[r];
	t[v][0] = max(fc[l] + t[r][0],t[l][0] + sc[r]);
	t[v][1] = max(sc[l] + t[r][1],t[l][1] + fc[r]);
	return;
}
int main() {
	int m; scanf("%d%d",&n,&m);
	scanf("%s",&s);
	build();
	while(m--) {
		char p[10];
		scanf("%s",&p);
		if(p[0] == 'c') {
			printf("%d\n",t[1][0]);
		} else {
			int l,r; scanf("%d%d",&l,&r);
			update(--l,--r);
		}
	}
}