#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n;
char s[200010];
int ans;
int main(){
	T=read();
	while(T--){
		ans=0;
		n=read();
		scanf("%s",s+1);
		int fir=0,lst=0;
		for(int i=1;i<=n;++i){
			int len=1;
			while(i<n&&s[i+1]==s[i]){
				++len;++i;
			}
			if(i==len) fir=len;
			else if(i==n) lst=len;
			else ans+=(len/3);
		}
		if(s[1]==s[n]) ans+=((fir+lst)/3);
		else ans+=fir/3+lst/3;
		if(fir==n){
			ans=1+(n-1)/3;
		}
		printf("%d\n",ans); 
	}
	return 0;
}