//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
const int Maxn = 1e6;
int s[Maxn],t[Maxn * 4],ans[Maxn];
map<int,int> mp;
vector<int> occ[Maxn];
inline int gcd(int a,int b){
	if(a < b)
		swap(a,b);
	return b?gcd(b,a%b):a;
}
void build(int v,int b,int e){
	if(e == b){
		t[v] = s[b];
		return;
	}
	int l = v << 1;
	int r = l | 1;
	int mid = b + e >> 1;
	build(l,b,mid);
	build(r,mid+1,e);
	t[v] = gcd(t[l],t[r]);
	return;
}
int query(int v,int b,int e,int i,int j){
	if(b > j || e < i)
		return 0;
	if(i <= b && e <= j)
		return t[v];
	int l = v << 1,r = l | 1,mid = b + e >> 1;
	return gcd(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}
int main(){
	int n;
	scanf("%d",&n);
	int x = 1;
	for(int i = 0; i < n;i++){
		scanf("%d",&s[i]);
		if(!mp[s[i]])
			mp[s[i]] = x++;
		occ[mp[s[i]]].push_back(i);
	}
	build(1,0,n-1);
	int m;
	scanf("%d",&m);
	for(int i = 0; i < m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		--l,--r;
		int fnd = query(1,0,n-1,l,r);
		int cnt = r - l + 1;
		if(mp[fnd]){
			l = lower_bound(occ[mp[fnd]].begin(),occ[mp[fnd]].end(),l) - occ[mp[fnd]].begin();
			r = upper_bound(occ[mp[fnd]].begin(),occ[mp[fnd]].end(),r) - occ[mp[fnd]].begin();
			printf("%d\n",cnt - (r - l));
		}else{
			printf("%d\n",cnt);
		}
	}
}