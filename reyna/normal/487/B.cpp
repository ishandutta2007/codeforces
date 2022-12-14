//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 1e5 + 1e3;
const int LOG = 20;
const int oo = (1 << 28);
int Min[Maxn],Max[Maxn],b,e,bg,ed;
int id[4 * Maxn];
int t[4 * Maxn];
int arr[Maxn];
int is_leaf[4 * Maxn],n;
void build(int v = 1,int b = 0,int e = n-1){
	if(b == e){
		is_leaf[v] = 1;
		id[b] = v;
		return;
	}
	int mid = b + e >> 1;
	int l = v << 1;
	int r = l | 1;
	build(l,b,mid);
	build(r,mid+1,e);
	return;
}
void update(int v,int x){
	if(!v)
		return;
	t[v] = min(x,t[v]);
	update(v >> 1,x);
	return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
	if(j < i)
		return oo;
	if(i < 0)
		return 0;
	if(e < i || b > j)
		return oo;
	if(i <= b && e <= j)
		return t[v];
	int l = v << 1;
	int r = l | 1;
	int mid = b + e >> 1;
	return min(query(i,j,l,b,mid),query(i,j,r,mid+1,e));
}
int main(){
	int s,l;
	scanf("%d%d%d",&n,&s,&l);
	for(int i = 0; i < n;i++)
		scanf("%d",&arr[i]);
	for(int i = 0; i < 4 * Maxn;++i)
		t[i] = oo;
	int st = 0;
	e = -1,ed = -1;
	build();
	int ans = 0;
	for(int i = 0; i < n;i++){
		while(e >= b && arr[Min[e]] >= arr[i]){
			e--;
		}
		while(ed >= bg && arr[Max[ed]] <= arr[i]){
//			cerr << Max[ed] << ' ' << i << endl;
			ed--;
		}
		Min[++e] = i;
		Max[++ed] = i;
		while(arr[Max[bg]] - arr[Min[b]] > s){
			st++;
			while(Min[b] < st){
				b++;
			}
			while(Max[bg] < st){
				bg++;
			}
		}
		if(i - st + 1 < l || arr[Max[bg]] - arr[Min[b]] > s){
			update(id[i],oo);
		}
		else{
			update(id[i],query(st-1,i-l)+1);
		}
		if(i == n-1)
			ans = query(st-1,i-l) + 1;
	}
	if(ans < oo){
		printf("%d\n",ans);
	}else
		printf("-1\n");
	return 0;
}