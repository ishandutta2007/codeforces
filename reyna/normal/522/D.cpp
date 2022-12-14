//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
const int oo = 1 << 28;
int t[4 * Maxn];
int arr[Maxn];
int ans[Maxn];
pair<int,pair<int,int> > do_query[Maxn];
map<int,int> get_id;
int n,m;
int query(int i,int j,int v = 1,int b= 0,int e = n-1){
	if(i <= b && e <= j)
		return t[v];
	if(j < b || i > e)
		return oo;
	int l = v << 1,r = l | 1,mid = b + e >> 1;
	return min(query(i,j,l,b,mid),query(i,j,r,mid+1,e));
}
void update(int idx,int val,int v = 1,int b = 0,int e = n-1){
	if(b == e){
		t[v] = val;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	if(idx < mid + 1)
		update(idx,val,l,b,mid);
	else
		update(idx,val,r,mid+1,e);
	t[v] = min(t[l],t[r]);
	return;
}
int main(){
	int cnt = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n;i++){
		scanf("%d",&arr[i]);
		do_query[cnt++] = make_pair(i,make_pair(0,arr[i]));
		update(i,oo);
	}
	for(int i = 0; i < m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		--l,--r;
		do_query[cnt++] = make_pair(r,make_pair(i+1,l));
	}
	sort(do_query,do_query+cnt);
	for(int i = 0; i < cnt;i++){
		int t = do_query[i].second.first;
		if(t){
			--t;
			int l = do_query[i].second.second,r = do_query[i].first;
			ans[t] = query(l,r);
		}else{
			int pos = do_query[i].first,val = do_query[i].second.second;
			int x = get_id[val];
			get_id[val] = pos+1;
			int dis = 0;
			if(!x)
				continue;
			--x;
			dis = pos - x;
			update(x,dis);
		}
	}
	for(int i = 0; i < m;i++)
		if(ans[i] == oo)
			printf("-1\n");
		else
			printf("%d\n",ans[i]);
}