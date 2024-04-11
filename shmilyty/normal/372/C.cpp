#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MaxN=152000;
ll n,m,d,sum;
ll a[MaxN],b[MaxN],t[MaxN],f[2][152000],q[MaxN];
template <class G> inline void read(G&x)
{
	bool f;char ch=getchar();
	for(f=false;!isdigit(ch);ch=getchar())if(ch=='-')f=true;
	for(x=0;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	x*=f==1?-1:1;
}
inline int abs(int x)
{
	if(x<0) return -x;
	return x;
}
signed main()
{
	read(n),read(m),read(d);
	memset(f,0x3f3f3f,sizeof(f));
	for(register int i=1;i<=m;i++) read(a[i]),read(b[i]),read(t[i]),sum+=b[i];
	for(register int i=1;i<=n;i++) f[1][i]=abs(a[1]-i);
	for(register int i=2;i<=m;i++)
{
		int now=i&1,last=i&1^1,ti=t[i]-t[i-1];
		memset(f[now],0x3f3f3f,sizeof(f[now]));
		int head=1,tail=0;
		for(register int j=1;j<=n;j++){
			while (head<=tail&&q[head]<j-ti*d) ++head;
			while (head<=tail&&f[last][q[tail]]>f[last][j]) --tail;
			q[++tail]=j;
			f[now][j]=min(f[now][j],f[last][q[head]]+abs(a[i]-j));
		}
		head=1,tail=0;
		for(register int j=n;j>=1;j--){
			while (head<=tail&&q[head]>j+ti*d) ++head;
			while (head<=tail&&f[last][q[tail]]>f[last][j]) --tail;
			q[++tail]=j;
			f[now][j]=min(f[now][j],f[last][q[head]]+abs(a[i]-j));
		}		
	}
	ll ans=INT_MAX/2;
	for(register int i=1;i<=n;i++) ans=min(f[m&1][i],ans);
	cout<<sum-ans;
	return 0;
}