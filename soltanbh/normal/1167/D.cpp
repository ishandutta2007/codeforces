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

const int N=5e5+9;

int n,t,ans[N],mark[N],p,b[N];
string s;

void solve(int l,int r,bool col){
	if(l>r) return ;
	if(b[l]==r){
		ans[l]=col,ans[r]=col;
		solve(l+1,r-1,1-col);
	}
	else{
		if(s[b[l]+1]==')')
			cout<<l<<" "<<r<<" !"<<b[l]+1<<endl;
		//if(b[l]+1==')') cout<<l<<" "<<r<<endl;
		solve(l,b[l],col);
		solve(b[l]+1,r,col);
	}
}
int main(){
	mark[0]=-1;
	cin>>n>>s;
	f(i,0,n){
		p+=(s[i]=='(');
		p-=(s[i]==')');
		if(s[i]==')')
			b[i]=mark[p]+1,b[mark[p]+1]=i;
			mark[p]=i;
		//cout<<p<<" ";
	}
	cout<<endl;
	//print(b,n);
	solve(0,n-1,0);
	f(i,0,n) cout<<ans[i];
}