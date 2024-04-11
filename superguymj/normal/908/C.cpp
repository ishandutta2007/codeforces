#include<bits/stdc++.h>
#define gc (S==T&&(T=(S=O)+fread(O,1,1<<14,stdin),S==T)?-1:*S++)

using namespace std;
typedef long long LL;
const int N=1002,inf=1e9+1;
char O[1<<14],*S=O,*T=O;

inline int read(){
	int x=0,f=1; char ch=gc;
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=gc;}
	while(ch>='0' && ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=gc;}
	return x*f;
}

long double a[N],p[N];
int n,r,i,j;

int main(){
	n=read(),r=read(),i,j;
	for(i=1; i<=n; ++i) a[i]=read();
	p[1]=r;
	for(i=2; i<=n; ++i)
	{
		p[i]=r;
		for(j=1; j<i; ++j)
		{
			if(fabs(a[j]-a[i])-1e-8>r+r) continue;
			p[i]=max(p[i],sqrt(r*r*4.0-(a[j]-a[i])*(a[j]-a[i]))+p[j]);
		}
	}
	for(i=1; i<=n; ++i) printf("%.8Lf ",p[i]);
	puts("");
	return 0;
}