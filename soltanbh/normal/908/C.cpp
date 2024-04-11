#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define ld long double

const int N=5e5+99;

int n,R,a[N];
ld ans[N];

void solve(int x){
	ld l=R,r=1e8+1,mid;
	f(i,0,x)
		if(abs(a[x]-a[i])<=2*R) maxm(l,ans[i]);
	for(int i=0;i<91;i++){
		bool check=0;
		mid=(l+r)/2;
		f(j,0,x)
			if(((ld)(a[x]-a[j]))*(a[x]-a[j])+(mid-ans[j])*(mid-ans[j])<=4*R*R)
				check=1;
		if(check) l=mid;
		else r=mid;
	}
	ans[x]=l;
	cout<<fixed<<setprecision(8)<<ans[x]<<" ";
}

int main(){
	cin>>n>>R;
	f(i,0,n) cin>>a[i];
	f(i,0,n)
		solve(i);
}