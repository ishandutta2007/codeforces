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
const int N = 5e5+10;
int n,k,m,s,a[N],b[N],c[N],C[N],l[N],Ans,pos,sum;
vector<int>ans;
inline void Del(int x){if (--c[a[x]]<C[a[x]]) sum--;}
inline void Add(int x){if (++c[a[x]]<=C[a[x]]) sum++;}
int main(){
	n=read(),k=read(),m=read(),s=read();
	For(i,1,n) a[i]=read();
	For(i,1,s) b[i]=read(),C[b[i]]++;
	int L=1;
	For(i,1,n){
		Add(i);bool flag=1;
		while (sum==s) Del(L++),flag=0;
		if (!flag) Add(--L);
		l[i]=(sum!=s)?-1:L;
	}
	Ans=1e9;
	For(i,1,n){
		if (l[i]==-1) continue;
		int L=(l[i]-1)/k*k+1,R=L+k-1,x=max(0,i-R);
		if (x<Ans) Ans=x,pos=i;
	}
	if (n-Ans<m*k) return puts("-1"),0;
	else {
		int L=(l[pos]-1)/k*k+1,R=L+k-1,x=max(0,pos-R);
		if (l[pos]-L>=x) For(i,L,L+x-1) ans.push_back(i);
		else {
			For(i,L,l[pos]-1) ans.push_back(i);int y=x-(l[pos]-L);
			memset(c,0,sizeof c);
			For(i,l[pos],pos){
				if (++c[a[i]]>C[a[i]]) y--,ans.push_back(i);
				if (!y) break;
			}
		}
	}
	printf("%d\n",ans.size());
	for (auto i:ans) printf("%d ",i);
}