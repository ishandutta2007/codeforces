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
ll n,m,k,Gcd,ans_x,ans_y;
int main(){
	n=read(),m=read(),k=read(),Gcd=__gcd(n*m,k);
	if (k/Gcd>2) return puts("NO"),0;
	Gcd=__gcd(n,k),ans_x=n/Gcd,k=k/Gcd;
	Gcd=__gcd(m,k),ans_y=m/Gcd,k=k/Gcd;
	if (k==1) (ans_x*2<=n)?ans_x<<=1:ans_y<<=1;
	puts("YES\n0 0"),printf("%lld 0\n",ans_x),printf("0 %lld\n",ans_y);
}