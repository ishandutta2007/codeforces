#include<bits/stdc++.h>
using namespace std;
typedef long long lxl;

inline lxl read(){
	lxl x=0,f=1;char ch=getchar();
	while(!isdigit(ch))(ch=='-')&&(f=-f),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}


int main(){
	for(int T=read();T;--T) printf("%lld\n",(read()+1)/10);
	return 0;
}