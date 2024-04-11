#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
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
#define int ll

const int N=1e6+99;

int n,t,a[N];

int ask(int l,int r){
	int x;
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>x;
	return x;
}
void Main(){
	cin>>n;
	int a1,a2,a3,p=ask(1,n);
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(ask(1,mid)==0) l=mid;
		else r=mid;
	}	
	a1=l;
	a2=a1+p-ask(a1+1,n);
	a2++;
	a3=a2+ask(a2,n)-ask(a2+1,n);
	cout<<"! "<<a1<<" "<<a2<<" "<<a3<<endl;
}

main(){
	cin>>t;
	while(t--){
		Main();
	}
}