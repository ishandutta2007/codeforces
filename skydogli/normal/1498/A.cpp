#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int calc(int a){
	int s=0;
	while(a){
		s+=a%10;
		a/=10;
	}
	return s;
}
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
signed main(){
	int T=read();
	while(T--){
		int n;
		cin>>n;
		for(int t=n;;++t){
			if(gcd(calc(t),t)!=1){
				printf("%lld\n",t);
				break;
			}
		}
	}
	return 0;
}