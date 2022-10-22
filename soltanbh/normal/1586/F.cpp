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

const int N=2005;

int n,k,m,a[N],g[N][N],dp[N];
vector<pair<int,int> > v;

int saghf(int x,int y){
	return (x+y-1)/y;
}
int p(int x,int y){
	int ans=1;
	f(i,0,y) ans*=x;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	f(i,1,n+1){
		if(p(k,i)>=n){
			m=i;
			break;
		}
	}
	cout<<m<<endl;
	f_(i,n,1){
		dp[i]=n-i;
		f(j,i+1,n+1){
			int x=-1,u=dp[i],v=dp[j];
			f(l,0,m){
				if(u%k>v%k){
					x=l;
					break;
				}
				u/=k,v/=k;
			}
			g[i][j]=x;
		}
	}
	f(i,1,n+1)
		f(j,i+1,n+1)
			cout<<g[i][j]+1<<" ";
}