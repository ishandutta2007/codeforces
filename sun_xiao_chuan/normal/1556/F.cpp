#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define cnt(x) __builtin_popcount(x)
#define M 1000000007
int i,j,k,n,m,t,l,r;
ll res,a[16],f[100500],tmp,v1[16],v2[16],it1,it2,p[16][16];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

void get(int x){
	int i,j,k;
	if(cnt(x)==1){f[x]=1;return;}
	f[x]=1;
	ll tmp;
	for(i=(x&(x-1));i;i=((i-1)&x)){
		it1=it2=0;
		tmp=f[i];
		for(j=1;j<=n;j++){
			if(!(x&b(j))){
				continue;
			}
			if(i&b(j)){
				v1[++it1]=j;
			}
			else{
				v2[++it2]=j;
			}
		}
		for(j=1;j<=it1;j++){
			for(k=1;k<=it2;k++){
				tmp=tmp*p[v1[j]][v2[k]]%M;
			}
		}
		f[x]=(f[x]+M-tmp)%M;
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			p[i][j]=a[i]*ksm(a[i]+a[j],M-2)%M;
			//printf("b%d %d %d\n",i,j,p[i][j]);
		}
	}
	for(i=1;i<b(n+1);i++){
		get(i);
		//printf("a%d %d\n",i,f[i]);
		tmp=f[i]*cnt(i)%M;
		it1=it2=0;
		for(j=1;j<=n;j++){
			if(i&b(j)){
				v1[++it1]=j;
			}
			else{
				v2[++it2]=j;
			}
		}
		for(j=1;j<=it1;j++){
			for(k=1;k<=it2;k++){
				//printf("b%d %d %d\n",v1[j],v2[k],p[v1[j]][v2[k]]);
				tmp=tmp*p[v1[j]][v2[k]]%M;
			}
		}
		res=(res+tmp)%M;
	}
	printf("%lld",res%M);
}