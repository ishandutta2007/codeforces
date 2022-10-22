#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005;

int t,n,u,mex,a[N],mark[N];
vector<int> ans;

int Mex(){
	f(i,0,n+1) mark[i]=0;
	f(i,0,n) mark[a[i]]++;
	f(i,0,n+1)
		if(!mark[i])
			return i;	
}
void do_it(int x){
	f(i,0,n) if(a[i]==x) ans.pb(i),a[i]=Mex();
	ans.pb(x);	
	a[x]=x;
}

int main(){
	cin>>t;
	f(q,0,t){
		ans.clear();
		cin>>n;
		f(i,0,n) cin>>a[i];
		while((u=Mex())!=n){
			ans.pb(u);
			a[u]=u;
		}
		f(i,0,n)
			if(a[i]!=i)
				do_it(i);
		cout<<ans.size()<<endl;
		f(i,0,ans.size()) cout<<ans[i]+1<<" "; cout<<endl;
	}
}