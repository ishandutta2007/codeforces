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

int n,t,m,a[N];
string s[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f(i,0,n){
		cin>>s[i];
	}
	f(i,1,n){
		f(j,0,m-1){
			if(s[i][j]=='X' && s[i-1][j+1]=='X'){
				a[j+1]=1;
			}
		}
	}
	f(i,1,N) a[i]+=a[i-1];
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		l--,r--;
		if(a[r]==a[l]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}