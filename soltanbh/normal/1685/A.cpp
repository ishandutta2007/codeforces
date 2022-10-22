#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,a[N],b[N];

void Main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	if(n&1){
		cout<<"NO"<<'\n';
		return ;
	}
	sort(a,a+n);
	f(i,0,n/2){
		b[i*2]=a[i];
		b[i*2+1]=a[i+n/2];
	}
	f(i,0,n) if(b[i]==b[(i+1)%n] || (b[i]<b[(i+n-1)%n])!=(b[i]<b[(i+1)%n])){
		cout<<"NO"<<'\n';
		return ;
	}
	cout<<"YES"<<'\n';
	f(i,0,n) cout<<b[i]<<" "; cout<<endl;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}