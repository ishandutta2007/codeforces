#include<bits/stdc++.h>
using namespace std;

const int N=10000005;
int p[N],mu[N],m,n,v[N],a[N],b[N];
long long ans;
int main(){
	scanf("%d",&n);
	if(n==1){printf("0\n");return 0;}
	if(n==2){printf("0\n");return 0;}
	if(n==3){printf("0\n");return 0;}
	if(n==4){printf("1\n");return 0;}
	if(n==5){printf("1\n");return 0;}
	v[1]=1;mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i]){
			v[i]=i;
			p[m++]=i;
			mu[i]=-1;
		}else a[i]=1,b[v[i]]++;
		for(int j=0;j<m&&1ll*p[j]*i<=n;j++){
			int k=i*p[j];v[k]=p[j];
			if(i%p[j]){
				mu[k]=-mu[i];
			}else{
				mu[k]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=2;i<=n;i++)b[i]+=b[i-1];
	
	int k=0;for(;k<m&&p[k]<=n/2;k++);
	int j=k;
	for(int i=0;i<k;i++){
		for(;j>=i&&1ll*p[i]*p[j]>n;j--);
		if(j<i)j=i;
		ans+=(j-i)*2+(k-j-1)*3;
	}
	
	for(int i=0;i<k;i++){
		int q=p[i],x=n/q-1,y=b[n/q],z;
		for(int j=q+q;j<=n;j+=q)if(v[j]<=n/q)y--;
		z=a[n]-x-y;
		ans+=x+2*y+3*z;
	}
	
	long long r=1ll*a[n]*(a[n]-1)/2;
	for(int d=2;d<=n;d++){
		int t=n/d;
		if(v[d]==d)t--;
//		printf("%d %d\n",d,t);
		r+=1ll*mu[d]*t*(t-1)/2;
	}
	ans+=1ll*a[n]*(a[n]-1)/2+r;
	
	printf("%I64d\n",ans);
	return 0;
}