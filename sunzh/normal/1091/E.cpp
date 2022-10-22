#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[500010];
int b[500010];
long long sum[500010],suf[500010];
inline int check(int md){//bigger 0  good  1  less  2
//printf("%lld\n",md);
	for(int i=1;i<=n;++i) b[i]=a[i];
	b[n+1]=md;
	sort(b+1,b+n+2);
	reverse(b+1,b+n+2);
	for(int i=1;i<=n+1;++i) sum[i]=sum[i-1]+b[i];
	for(int i=n+1;i>=1;--i) suf[i]=suf[i+1]+b[i];
	if(sum[n+1]>1ll*(n+1)*n) return 0;
	for(int i=n;i>=1;--i){
		long long x=1ll*i*(i-1);
		int l=i+1,r=n+1,j=i;
		while(l<=r){
			int mid=l+r>>1;
			if(b[mid]>i){
				l=mid+1,j=mid;
			}
			else r=mid-1;
		}
		x+=suf[j+1]+1ll*(j-i)*i;
//		printf("x:%d,sum:%d\n",x,sum[i]);
		if(sum[i]>x) return md<b[i]?2:0;
	}
	return 1;
}
signed main(){
	n=read();
	int cnt=0;
	long long s=0;
	for(int i=1;i<=n;++i) a[i]=read(),s+=a[i],cnt+=(a[i]==n);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int l=0,r=n>>1;
	int minn=0x3f3f3f3f,maxn=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check((mid<<1)+(s&1))<=1){
			r=mid-1,minn=(mid<<1)+(s&1);
		}
		else{
			l=mid+1;
		}
	}
	minn=max(cnt+(int)((s+cnt)&1),minn);
	l=0,r=n>>1;
	while(l<=r){
//		printf("l:%d,r:%d\n",l,r);
		int mid=l+r>>1;
		if(check((mid<<1)+(s&1ll))>=1){
			maxn=(mid<<1)+(s&1ll),l=mid+1;
		}
		else r=mid-1;
//		printf("l:%d,r:%d\n",l,r);
	}
	if(minn<=maxn) for(int i=minn;i<=maxn;i+=2) printf("%d ",i);
	else printf("-1\n");
}