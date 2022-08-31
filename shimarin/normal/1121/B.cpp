#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
#define Debug(x) cerr<<#x<<"="<<(x)<<endl
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 1010;
int n,a[N],b[1000010];
int main(){
	n=read();
	For(i,1,n) a[i]=read();
	int ans=0;
	For(i,1,n) For(j,i+1,n) b[a[i]+a[j]]++,ans=max(ans,b[a[i]+a[j]]);
	printf("%d\n",ans);
}