#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+9;

int n,ans1=-1,ans2,par[N];
pair<int,int> m,p[N],tree[N*2];
vector<pair<int,int> > v[N];
set<pair<int,int> > s;

pair<int,int> query(int l, int r) {
	pair<int,int> res; res.F=res.S=-1;
	r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if(l&1){
			if(tree[l].F>res.F)
				res=tree[l];
			l++;
		}
   	if(r&1){
			if(tree[--r].F>res.F)
				res=tree[r];
		}
	}
	return res;
}
void make_tree(){
	f_(i,n-1,1){
		pair<int,int> p1=tree[i*2],p2=tree[i*2+1];
		if(p1.F>p2.F) tree[i]=p1;
		else tree[i]=p2;
	}
}

int main(){
	cin>>n;
	f(i,0,n){
		Gett(p[i].F,p[i].S);
		p[i].F--,p[i].S--;
		v[p[i].F].pb(mp(p[i].S,i));
	}
	
	f(i,0,n){
		f(j,0,v[i].size())
			s.insert(v[i][j]);
		pair<int,int> u=*s.begin();
		s.erase(u);
		tree[i+n]=u;
		par[u.S]=i;
	}
	make_tree();
	
	f(i,0,n){
		m=query(p[i].F,par[i]-1);
		if(m.F>=par[i])
			ans1=i,ans2=m.S;
	}
	if(ans1==-1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	f(i,0,n) cout<<par[i]+1<<" "; cout<<endl;
	
	if(ans1!=-1){
		swap(par[ans1],par[ans2]);
		f(i,0,n) cout<<par[i]+1<<" ";
	}
}
/*5
2 2
3 3
1 2
1 5
4 4*/