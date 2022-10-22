#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,a1,b1,a2,b2;
inline int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	int B=gcd(n,m);
	for(int i=1;i<=q;++i){
		cin>>a1>>b1>>a2>>b2;
		b1--;b2--;
		if(a1==1)b1/=(n/B);
			else b1/=(m/B);
		if(a2==1)b2/=(n/B);
			else b2/=(m/B);
		cout<<(b1==b2?"YES":"NO")<<endl;
	}
	return 0;
}