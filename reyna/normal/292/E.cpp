//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 9;
int t[4 * Maxn],change[4 * Maxn],from[Maxn],to[Maxn];
int n,q;
void prop(int v,int l,int r,int sz){
	change[l] = change[v];
	change[r] = change[v] + sz;
	t[l] = change[v];
	t[r] = change[v] + sz;
	change[v] = -1;
	return;
}
void update(int i,int j,int x,int v = 1,int b = 0,int e = n-1){
//	cerr << v << ' ' << b << ' ' << e << ' ' << x << endl;
	if(i > e || b > j)
		return;
	if(i <= b && e <= j){
		t[v] = x;
		change[v] = x;
		return;
	}
	int l = v << 1,r = l | 1,mid = b + e >> 1,sz = mid - b + 1;
	if(change[v] + 1)
		prop(v,l,r,sz);
	update(i,j,x,l,b,mid);
	update(i,j,x+max(0,mid - max(i,b) + 1),r,mid+1,e);
	return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j)
		return -1;
	if(i <= b && e <= j)
		return t[v];
	int l = v << 1,r = l | 1,mid = b + e >> 1,sz = mid - b + 1;
	if(change[v] + 1)
		prop(v,l,r,sz);
	return max(query(i,j,l,b,mid),query(i,j,r,mid+1,e));
}
int main(){
	scanf("%d%d",&n,&q);
	memset(t,-1,sizeof t);
	memset(change,-1,sizeof change);
	for(int i = 0; i < n;i++)
		scanf("%d",&from[i]);
	for(int i = 0; i < n;i++)
		scanf("%d",&to[i]);
	for(int i = 0; i < q;i++){
		int c;
		scanf("%d",&c);
		if(--c){
			int v;
			scanf("%d",&v);
			--v;
			int x = query(v,v);
			if(x + 1)
				printf("%d\n",from[x]);
			else
				printf("%d\n",to[v]);
		}else{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			--x,--y;
			update(y,y+k-1,x);
		}
	}
}