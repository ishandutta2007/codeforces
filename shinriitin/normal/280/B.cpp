#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 100005

int n,s[max_N],st[max_N],top,ans; 

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i)s[i]=gint();
		ans=0;
		top=0;
		for(int i=1;i<=n;++i){
			while(top&&st[top]<s[i])ans=max(ans,st[top--]^s[i]);
			st[++top]=s[i];
		}
		top=0;
		for(int i=n;i;--i){
			while(top&&st[top]<s[i])ans=max(ans,st[top--]^s[i]);
			st[++top]=s[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}