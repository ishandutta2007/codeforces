#include<bits/stdc++.h>
const int N=1000006,M=1000000007;
using namespace std;
typedef long long ll;
ll now,sum;
int n,x[N],y[N],sx[N],sy[N],s1[N],s2[N],ans;
inline ll mul(int a,int b){
	return 1ll*x[a]*y[b]-1ll*x[b]*y[a];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d",x+i,y+i),
	x[i+n]=x[i],y[i+n]=y[i];
	for(int i=1;i<=n*2;i++){
		sx[i]=(sx[i-1]+x[i])%M;
		sy[i]=(sy[i-1]+y[i])%M;
		if(i<n+2)sum+=mul(i,i-1);
		s1[i]=(s1[i-1]+mul(i,i-1))%M;
		s2[i]=(s2[i-1]+s1[i])%M;
	}
	for(int i=1,j=1;i<=n;i++){
		now-=mul(i,i-1);
		for(;j<=i||now+mul(j,j-1)+mul(i,j)<=sum/2;j++)
		now+=mul(j,j-1);
		j--,now-=mul(j,j-1);
		ans=(ans+sum%M*(j-i-1)-2*(s2[j]-s2[i]-1ll*s1[i]*(j-i)
		+1ll*x[i]*(sy[j]-sy[i])-1ll*y[i]*(sx[j]-sx[i])))%M;
		ans=(ans-sum%M*(i+n-j-2)+2*(s2[i+n-2]-s2[j]-1ll*s1[i]*(i+n-j-2)
		+1ll*x[i]*(sy[i+n-2]-sy[j])-1ll*y[i]*(sx[i+n-2]-sx[j])))%M;
	}
	printf("%d",(ans*(M+1ll)/2%M+M)%M);
}