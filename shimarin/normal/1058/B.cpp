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
using namespace std;
int n,d,m,x,y,n1;
struct P{int x,y;}p1,p2,p3,p4;
inline int get(P p1,P p2,P p){return (p2.x-p1.x)*(p.y-p1.y)-(p.x-p1.x)*(p2.y-p1.y);}
inline int check(P p1,P p2,P p3,P p4,P p){return get(p1,p2,p)*get(p3,p4,p)>=0&&get(p2,p3,p)*get(p4,p1,p)>=0;}
int main(){
    n=read(),d=read(),m=read();
    p1=(P){0,d},p2=(P){n-d,n},p3=(P){n,n-d},p4=(P){d,0};
    while(m--){
        x=read(),y=read();
        if (check(p1,p2,p3,p4,(P){x,y})) puts("YES");
        	else puts("NO");
    }
}