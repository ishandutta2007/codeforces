#include <cstdio>
#include <cstring>
const int Maxn=500;
int n,Mod;
int f[2][Maxn*Maxn+5];
int sum_f[2][Maxn*Maxn+5];
int s_f_1[2][Maxn*Maxn+5],s_f_2[2][Maxn*Maxn+5];
int val[Maxn+5];
int N;
int find_sum(int *s,int l,int r){
	if(r>N){
		r=N;
	}
	if(r<0){
		return 0;
	}
	if(l<0){
		return s[r];
	}
	return (s[r]-s[l]+Mod)%Mod;
}
void calc_1(int *f,int *s){
	s[0]=f[0];
	for(int i=1;i<=N;i++){
		s[i]=(s[i-1]+f[i])%Mod;
	}
}
void calc_2(int *f,int *s){
	s[0]=0;
	for(int i=1;i<=N;i++){
		s[i]=(s[i-1]+1ll*i*f[i])%Mod;
	}
}
int main(){
	scanf("%d%d",&n,&Mod);
	if(n==1){
		puts("0");
		return 0;
	}
	f[0][0]=1;
	val[0]=1;
	calc_1(f[0],sum_f[0]);
	int cur=0,nxt;
	for(int i=1;i<=n;i++){
		nxt=cur^1;
		memset(f[nxt],0,sizeof f[nxt]);
		N=i*(i+1)>>1;
		for(int j=0;j<=i*(i-1)>>1;j++){
			f[nxt][j]=find_sum(sum_f[cur],j-i,j);
		}
		calc_1(f[nxt],sum_f[nxt]);
		calc_1(sum_f[nxt],s_f_1[nxt]);
		calc_2(sum_f[nxt],s_f_2[nxt]);
		for(int j=0;j<=i*(i-1)>>1;j++){
			val[i]=(val[i]+1ll*f[nxt][j]*(i+j+1)%Mod*find_sum(s_f_1[nxt],j,j+i))%Mod;
			val[i]=(val[i]-1ll*f[nxt][j]*find_sum(s_f_2[nxt],j,j+i)%Mod+Mod)%Mod;
		}
		cur=nxt;
	}
	int ans=0,sum=1;
	int pow_2=0;
	for(int i=0,tmp=1;i<n;i++){
		int cur_i=i+1;
		while(!(cur_i&1)){
			cur_i>>=1;
			pow_2++;
		}
		sum=1ll*sum*cur_i%Mod;
		ans=(ans+1ll*tmp*val[n-i-1])%Mod;
		tmp=1ll*tmp*(n-i)%Mod;
	}
	int tmp_sum_1=sum,tmp_sum_2,tmp_sum_3;
	for(int i=1;i<pow_2;i++){
		tmp_sum_1=(tmp_sum_1<<1)%Mod;
	}
	tmp_sum_2=tmp_sum_1;
	tmp_sum_2=(tmp_sum_2<<1)%Mod;
	tmp_sum_3=tmp_sum_2;
	tmp_sum_2=(tmp_sum_2-1+Mod)%Mod;
	sum=(1ll*tmp_sum_1*tmp_sum_2+tmp_sum_3)%Mod;
	ans=(sum-ans+Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}