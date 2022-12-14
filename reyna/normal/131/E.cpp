//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 9;
int u[Maxn],d[Maxn],l[Maxn],r[Maxn],hid1[Maxn],lod1[Maxn],hid2[Maxn],lod2[Maxn];
int x[Maxn],y[Maxn],ans[Maxn],t[Maxn];
int main(){
	for(int i = 0; i < Maxn;i++) u[i] = -1,d[i] = -1,l[i] = -1,r[i] = -1,hid1[i] = -1,lod1[i] = -1,hid2[i] = -1,lod2[i] = -1;
	int n,m;
	cin >> n >> m;
	for(int k = 0; k < m;k++){
		cin >> x[k] >> y[k];
		x[k]--,y[k]--;
		int i = x[k],j = y[k];
		if(u[j] == -1 || x[u[j]] > i) u[j] = k;
		if(d[j] == -1 || x[d[j]] < i) d[j] = k;
		if(l[i] == -1 || y[l[i]] > j) l[i] = k;
		if(r[i] == -1 || y[r[i]] < j) r[i] = k;
		if(hid1[i+j] == -1 || x[hid1[i+j]] < i) hid1[i+j] = k;
		if(lod1[i+j] == -1 || x[lod1[i+j]] > i) lod1[i+j] = k;
		if(hid2[i-j+n-1] == -1 || x[hid2[i-j+n-1]] < i) hid2[i-j+n-1] = k;
		if(lod2[i-j+n-1] == -1 || x[lod2[i-j+n-1]] > i) lod2[i-j+n-1] = k;
		ans[k] = 8;
	}
	for(int i = 0; i < Maxn;i++){
		if(u[i] != -1) ans[u[i]]--;
		if(d[i] != -1) ans[d[i]]--;
		if(l[i] != -1) ans[l[i]]--;
		if(r[i] != -1) ans[r[i]]--;
		if(hid1[i] != -1) ans[hid1[i]]--;
		if(hid2[i] != -1) ans[hid2[i]]--;
		if(lod1[i] != -1) ans[lod1[i]]--;
		if(lod2[i] != -1) ans[lod2[i]]--;
	}
	for(int i = 0; i < m;i++){
		t[ans[i]]++;
	}
	for(int i = 0; i <= 8;i++){
		cout << t[i] << ' ';
	}
	return 0;
}