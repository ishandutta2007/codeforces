#include<iostream>
using namespace std;
#define int long long
int T,f[10000],n;
int a(int x){if(x==1) return 1e18;if(x%10) return 0;if(x==10) return 1;return 10*a(x/10);}
int b(int x){for(int i=1;1;i*=10) if(x==i*10) return i;else if(x%i) return i/10;}
signed main(){
	for(cin>>T;T--;cout<<endl){
		cin>>f[1]>>n;
		for(int i=1,mx=1;i<n;f[++i]=b(f[mx]),f[mx]-=b(f[mx]),mx=1)
			for(int j=2;j<=i;++j) mx=(a(f[mx])<a(f[j])?mx:j);
		for(int i=1;i<=n;++i) cout<<f[i]<<" ";
	}
	return 0;
}