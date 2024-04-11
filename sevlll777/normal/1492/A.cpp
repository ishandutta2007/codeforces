#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int T,p,a,b,c;
signed main(){
	T=read();
	while(T--){
		p=read(),a=read(),b=read(),c=read();
		printf("%lld\n",min((p+a-1)/a*a-p,min((p+b-1)/b*b-p,(p+c-1)/c*c-p)));
	}
	return 0;
}