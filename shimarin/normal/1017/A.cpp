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
const int N = 1010;
struct node{
	ll x,y;
}a[N];
int n;
inline bool cmp(node a,node b){return a.x==b.x?a.y<b.y:a.x>b.x;}
int main(){
	n=read();
	For(i,1,n) a[i]=(node){read()+read()+read()+read(),i};
	sort(a+1,a+1+n,cmp);
	For(i,1,n) if (a[i].y==1) return printf("%d",i),0;
}