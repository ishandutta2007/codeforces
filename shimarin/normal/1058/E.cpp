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
const int N = 3e5+10;
int n;
ll ans,sum[N][2],a[N],pre[N];
inline int Get(ll x){
	int sum=0;
	while (x) sum+=x&1,x>>=1;
	return sum;
}
int main(){
	n=read();
	For(i,1,n) a[i]=Get(read()),pre[i]=pre[i-1]+a[i];
	sum[0][0]=1;
	For(i,1,n) sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1],ans+=sum[i][pre[i]&1],sum[i][pre[i]&1]++;
	//For(i,1,n) printf("%lld ",a[i]);puts("");
	For(i,1,n){
		int l=i,r=i,Sum=a[i];
		while (l!=0){
			if (a[l-1]>a[i]||(Sum+a[l-1])/2>a[i]) break;
			Sum+=a[--l];
		}
		if (l==0) l++;
		Sum=a[i];
		while (r!=n+1){
			if (a[r+1]>a[i]||(Sum+a[r+1])/2>a[i]) break;
			Sum+=a[++r];
		}
		if (r==n+1) r--;
		For(j,i,r){
			while ((pre[j]-pre[l-1])/2>=a[i]&&l<=i) l++;
			if (l>i) break;
			ans-=sum[i-1][pre[j]&1]-(l-2>=0?sum[l-2][pre[j]&1]:0);
		}
		//printf("%d %d %d\n\n",l,r,ans);
	}
	printf("%lld",ans);
}