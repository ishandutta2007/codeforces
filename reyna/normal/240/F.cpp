//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 4e5 + 9;
const int Maxc = 26;
int n,m;
char S[Maxn];
int t[Maxn][Maxc],change[Maxn][Maxc];
int cnt[Maxc];
void prop(int v,int c,int l,int r,int sz1,int sz2){
	change[l][c] = change[v][c],change[r][c] = change[v][c];
	t[l][c] = (change[v][c] - 1) * sz1,t[r][c] = (change[v][c] - 1) * sz2;
	change[v][c] = 0;
	return;
}
void update(int i,int j,int c,int set_to,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j) return;
	if(i <= b && e <= j){
		t[v][c] = (e - b + 1) * set_to;
		change[v][c] = set_to + 1;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	if(change[v][c]) prop(v,c,l,r,mid - b + 1,e - mid);
	update(i,j,c,set_to,l,b,mid);
	update(i,j,c,set_to,r,mid+1,e);
	t[v][c] = t[l][c] + t[r][c];
	return;
}
int query(int i,int j,int c,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) return t[v][c];
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	if(change[v][c]) prop(v,c,l,r,mid - b + 1,e - mid);
	return query(i,j,c,l,b,mid) + query(i,j,c,r,mid+1,e);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&S);
	for(int i = 0; i < n;i++) update(i,i,S[i] - 'a',1);
	for(int q = 0; q < m;q++){
		int l,r;
		scanf("%d%d",&l,&r);
		--l,--r;
		int parity = 0;
		for(int i = 0; i < Maxc;i++) cnt[i] = query(l,r,i),parity += cnt[i] % 2;
		if(parity > 1) continue;
		int cur = 0;
		for(int i = 0; i < Maxc;i++){
			int half = cnt[i] / 2;
			int mid = l + r >> 1;
			update(l,r,i,0);
			if(cnt[i] % 2) update(mid,mid,i,1);
			update(l+cur,l+cur+half-1,i,1);
			update(r-cur-half+1,r-cur,i,1);
			cur += half;
		} 
	}
	for(int i = 0;i < n;i++){
		for(int c = 0;c < Maxc;c++){
			if(query(i,i,c))
				cout << char(c + 'a');
		}
	}
	return 0;
}