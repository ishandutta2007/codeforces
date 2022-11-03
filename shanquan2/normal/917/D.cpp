#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
int x[105],y[105],n,cnt,ans[105],p[105];
long long a[105][105],b[105];
bool v[105][105];
int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);tmp=1ll*tmp*tmp%M;
	return (t&1)?1ll*tmp*x%M:tmp;
}
void change(int k,int i){
	for(int j=0;j<cnt;j++)swap(a[k][j],a[i][j]);
}
long long calc(){
	long long ans=1;
	int f=1;
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++)if(a[j][i]){
			while(a[i][i] && a[j][i]){
				if(abs(a[j][i])<abs(a[i][i]))
					change(j,i),f=-f;
				long long t=a[j][i]/a[i][i];
				for(int l=i;l<cnt;l++)
					a[j][l]-=a[i][l]*t,a[j][l]%=M;
			}
			if(a[i][i]==0)change(j,i),f=-f;
		}
	}
	for(int i=0;i<cnt;i++)
		ans*=a[i][i],ans%=M;
	return (ans*f+M)%M;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]--,y[i]--;
		v[x[i]][y[i]]=v[y[i]][x[i]]=1;
	}
	for(int t=0;t<n;t++){
		for(int i=0;i<n;i++)a[i][i]=0;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j){
			if(v[i][j]){
				a[i][j]=(M-t)%M;a[i][i]+=t;
			}else{
				a[i][j]=M-1;a[i][i]++;
			}
		}
		cnt=n-1;
		b[t]=calc();
	}
	for(int i=0;i<n;i++){
		memset(p,0,sizeof(p));
		p[0]=1;long long q=1;
		for(int j=0;j<n;j++)if(j!=i){
			for(int k=n-1;k;k--)p[k]=(p[k-1]-1ll*j*p[k]%M+M)%M;
			p[0]=(M-1ll*j*p[0]%M)%M;
			q=1ll*q*(i-j+M)%M;
		}
		long long t=1ll*b[i]*fexp(q,M-2)%M;
		for(int j=0;j<n;j++)ans[j]=(ans[j]+1ll*t*p[j])%M;
	}
	for(int i=0;i<n;i++)printf("%d ",ans[i]);printf("\n");
	return 0;
}