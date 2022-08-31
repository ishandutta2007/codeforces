#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 2e5+10;
ll n,x,a[N],l,r,b[N];
int main(){
	n=read(),a[n+1]=(ll)1e18+10;
	For(i,1,n>>1){
		x=read();
		if (x-a[i-1]>=a[n-i+2]) a[n-i+1]=a[n-i+2],a[i]=x-a[n-i+1];
		else if (x-a[n-i+2]<=a[i-1]) a[i]=a[i-1],a[n-i+1]=x-a[i];
	}
	For(i,1,n) printf("%lld ",a[i]);
}