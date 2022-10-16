#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long ll;
template<typename T>
inline void read(T &x){
	char c=getchar();T fh=0;bool f=false;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))fh=(fh<<1)+(fh<<3)+(c^48),c=getchar();
	x=f?-fh:fh;
	return;
}
int a[105],b[105],c[105],ans[105],n;
int main(){
	int T;
	read(T);
	while(T--){
		read(n);
		fr(i,1,n)read(a[i]);
		fr(i,1,n)read(b[i]);
		fr(i,1,n)read(c[i]);
		ans[1]=a[1];
		fr(i,2,n-1)if(a[i]!=ans[i-1])ans[i]=a[i];
		else if(b[i]!=ans[i-1])ans[i]=b[i];
		else if(c[i]!=ans[i-1])ans[i]=c[i];//2~n-1
		if(a[n]!=ans[1]&&a[n]!=ans[n-1])ans[n]=a[n];//
		else if(b[n]!=ans[1]&&b[n]!=ans[n-1])ans[n]=b[n];
		else if(c[n]!=ans[1]&&c[n]!=ans[n-1])ans[n]=c[n];
		fr(i,1,n)cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}