#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,u) for (register int i=first[u];i;i=last[i])
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
int n,Min,ans;
int main(){
	n=read(),Min=1e9;
	For(x,1,n)
		if (x+(n-1)/x+1<Min) Min=x+(n-1)/x+1,ans=x;
	Dow(i,(n-1)/ans+1,1)
		For(j,(i-1)*ans+1,min(i*ans,n)) printf("%d ",j);
}