#include <cstdio>
#include <cstring>
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
typedef long long ll;
const int Maxn=5000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
ll f[Maxn+5][Maxn+5];
int n,s,e;
int x[Maxn+5],a[Maxn+5],b[Maxn+5],c[Maxn+5],d[Maxn+5];
int main(){
	scanf("%d%d%d",&n,&s,&e);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]+=x[i];
		c[i]+=x[i];
		b[i]-=x[i];
		d[i]-=x[i];
	}
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		if(i!=s&&i!=e){
			for(int j=1;j<=i;j++){
				f[i][j]=min(f[i][j],f[i-1][j-1]+b[i]+d[i]);
				if(j>(i>e)||i==n){
					f[i][j]=min(f[i][j],f[i-1][j]+a[i]+d[i]);
				}
				if(j>(i>s)||i==n){
					f[i][j]=min(f[i][j],f[i-1][j]+b[i]+c[i]);
				}
				if(j+1>(i>e)+(i>s)||i==n){
					f[i][j]=min(f[i][j],f[i-1][j+1]+a[i]+c[i]);
				}
			}
		}
		else if(i==s){
			for(int j=1;j<=i;j++){
				if(j>(i>e)||i==n){
					f[i][j]=min(f[i][j],f[i-1][j-1]+d[i]);
					f[i][j]=min(f[i][j],f[i-1][j]+c[i]);
				}
			}
		}
		else{
			for(int j=1;j<=i;j++){
				if(j>(i>s)||i==n){
					f[i][j]=min(f[i][j],f[i-1][j-1]+b[i]);
					f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
				}
			}
		}
	}
	printf("%lld\n",f[n][1]);
	return 0;
}