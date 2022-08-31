#include<bits/stdc++.h>
#define inf 1000000000
#define N 1000009
using namespace std;

int n,cnt,sum[N],f[N],a[N]; char s[N];
int calc(int l,int r){
	if (l<1) l=1;
	//	cout<<"	"<<l<<' '<<r<<endl;
	if (l>r) return 0; return sum[r]-sum[l-1];
}
int getnxt(int i){
	if (i<1) i=1;
	return i>n?n+1:f[i];
}
bool check(int t){
	int i,x=0,y; a[0]=-inf;
	//puts("ok");
	for (y=1; y<=n; y++) if (s[y]=='*') break;
	for (i=1; i<=cnt; i++){
		int u=-inf,v=inf;
		if (a[i]-t<=y){
			u=max(u,a[i-1]+t); u=max(u,a[i]);
		}
		if (!calc(x+1,a[i]-t-1)){
			u=max(u,x); u=max(u,a[i]);
		}
		if (!calc(a[i-1]+t+1,a[i]-1)){
			if (a[i]<=y && y<=a[i]+t) v=getnxt(a[i]+t+1);
			else v=min(y,getnxt(a[i]+t+1));
		} else v=min(y,getnxt(a[i-1]+t+1));
		if (!calc(x+1,a[i]-1)){
			v=max(v,getnxt(a[i]+t+1));
		} else v=max(v,getnxt(x+1));
		//cout<<i<<' '<<u<<' '<<v<<endl;
		x=u; y=v;
	}
	for (i=a[cnt]+t+1; i<=n; i++) if (s[i]=='*') return 0;
	if (y>n) return 1;
	for (i=max(1,x+1); i<=n; i++) if (s[i]=='*') return 0;
	return 1;
}
int main(){
	scanf("%d%s",&n,s+1);
	int i;
	for (i=1; i<=n; i++) if (s[i]=='P') a[++cnt]=i;
	if (cnt==1){
		int x=0,y=0,t1=0,t2=0;
		for (i=1; i<a[1]; i++){
			if (s[i]=='*'){
				x++; if (!t1) t1=a[1]-i;
			}
		}
		for (i=n; i>a[1]; i--){
			if (s[i]=='*'){
				y++; if (!t2) t2=i-a[1];
			}
		}
		printf("%d ",max(x,y));
		int ans;
		if (x!=y) ans=(x>y?t1:t2); else ans=min(t1,t2);
		printf("%d\n",ans);
		return 0;
	}
	f[n+1]=n+1;
	for (i=n; i; i--) f[i]=(s[i]=='*'?i:f[i+1]);
	for (i=1; i<=n; i++) sum[i]=sum[i-1]+(s[i]=='*');
	int l=0,r=n,mid;
	//cout<<check(3);system("pause");
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) r=mid; else l=mid+1;
	}
	int x=0;
	for (i=1,x=0; i<=n; i++) x+=(s[i]=='*');
	printf("%d %d\n",x,l);
	return 0;
}