#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=4e5+99,inf=1e9;

int n,m,t,mx_el=-1,a[N],mn[N],mx[N],tree[N];
vector<int> ad[N],h[N];
set<int> s;

int query(int l, int r){
	int res=N;
	r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1)
   		minm(res,tree[l++]);
   	if (r&1)
   		minm(res,tree[--r]);
	}
  return res;
}
void make_a(){
	if(mx_el==-1){
		f(i,0,n)
			if(a[i]==inf){
				a[i]=m,mx_el=i;
				break;
			}
	}
	if(mx_el==-1){
		cout<<"NO";
		exit(0);
	}
}
void make_tree(){
	f(i,n,2*n)
		tree[i]=a[i-n];
	f_(i,n-1,0)
		tree[i]=min(tree[i*2],tree[i*2+1]);
}
bool check(){
	mn[1]=0,mx[1]=n-1;
	f(i,1,m+1){
		if(mn[i]!=-1 && query(mn[i],mx[i])<i)
			return 0;
		if(mn[i]==-1) mn[i]=mx_el,mx[i]=mx_el;
		mx[i]++;
		ad[mn[i]].pb(i),h[mx[i]].pb(i);
	}
	return 1;
}
void solve(){
	set<int> s;
	f(i,0,n){
		f(j,0,ad[i].size()) s.insert(ad[i][j]);
		f(j,0,h[i].size()) s.erase(h[i][j]);
		if(s.size())
			a[i]=*s.rbegin();
	}
}

int main(){
	fill(mn,mn+N,-1);
	cin>>n>>m;
	f(i,0,n){
		cin>>a[i];
		mx[a[i]]=i;
		if(mn[a[i]]==-1) mn[a[i]]=i;
		if(a[i]==0) a[i]=inf;
		if(a[i]==m) mx_el=i;
	}
	make_a();
	make_tree();
	if(!check()) return cout<<"NO",0;
	cout<<"YES"<<endl;
	solve();
	f(i,0,n) cout<<a[i]<<" ";
}