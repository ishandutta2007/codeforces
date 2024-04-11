#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,k,a[N],ans[N],par[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		cout<<"? ";
		f(j,1,n+1){
			cout<<2-(i==j)<<" ";
		}
		cout<<endl;
		cin>>k;
		if(k!=i) par[k]=i;
	}
	f(i,1,n+1){
		cout<<"? ";
		f(j,1,n+1){
			cout<<1+(i==j)<<" ";
		}
		cout<<endl;
		cin>>k;
		if(k!=i) par[i]=k;
	}
	int u=0;
	f(i,1,n+1){
		u=par[u];
		ans[u]=i;
	}
	cout<<"! "<<endl;
	f(i,1,n+1) cout<<ans[i]<<" ";
	cout<<endl;
}