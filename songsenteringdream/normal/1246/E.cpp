#include<cstdio>
#include<bitset>
using namespace std;
const int o=2010;
int n,k,a[16],b[16];bitset<o> f[1<<16];
inline int fnd(int S,int s){
	for(int i=0;i<n;++i) if(((S>>i)&1)&&s>=a[i]&&f[S^(1<<i)][s-a[i]]) return i;
	return n;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	f[0].set(0);
	for(int i=1;i<(1<<n);++i){
		for(int j=0;j<n;++j) if((i>>j)&1) f[i]|=f[i^(1<<j)]<<a[j];
		for(int j=2000/k;j;--j) if(f[i][j*k]) f[i].set(j);
	}
	if(!f[(1<<n)-1][1]){printf("NO\n");return 0;}
	printf("YES\n");
	for(int S=(1<<n)-1,s=1,t;S;){
		for(;s*k<=2000&&f[S][s*k];s*=k) for(int i=0;i<n;++i) b[i]+=((S>>i)&1);
		S^=(1<<(t=fnd(S,s)));s-=a[t];
	}
	for(int T=n,B,x=0,y=0;--T;--n){
		B=0;
		for(int i=0;i<n;++i) if(b[i]>B) B=b[i];
		for(int i=0;i<n;++i) if(b[i]==B) x=y,y=i;
		printf("%d %d\n",a[x],a[y]);
		for(a[x]+=a[y];a[x]%k==0;--b[x]) a[x]/=k;
		for(int i=0,j=0;i<n;++i) if(i^y) a[j]=a[i],b[j++]=b[i];
	}
	return 0;
}