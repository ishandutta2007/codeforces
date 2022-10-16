#include <cstdio>
#include <algorithm>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
typedef long long ll;
const int Maxn=270000;
const int Mod=998244353;
const int G=3;
typedef long long ll;
int x,ans,cnt=1,limit=-1;
int g[Maxn+5],g_0[Maxn+5],g_1[Maxn+5],g_2[Maxn+5],f_0[Maxn+5];
int f_1[Maxn+5],f_2[Maxn+5],tmp_1[Maxn+5],tmp_2[Maxn+5],tmp_3[Maxn+5],tmp_4[Maxn+5];
int p_0[Maxn+5],p_1[Maxn+5],tmp_g_0[Maxn+5],tmp_g_1[Maxn+5],tmp_g_2[Maxn+5];
void NTT(int *a,int flag,int n){
	static int R[Maxn+5],last_len=0;
	int len=1,L=0;
	while(len<n){
		len<<=1;
		L++;
	}
	if(len!=last_len){
		last_len=len;
		for(int i=0;i<len;i++){
			R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		}
	}
	for(int i=0;i<len;i++){
		if(i<R[i]){
			swap(a[i],a[R[i]]);
		}
	}
	for(int j=1;j<len;j<<=1){
		int T=quick_power(G,(Mod-1)/(j<<1),Mod);
		for(int k=0;k<len;k+=(j<<1)){
			for(int l=0,t=1;l<j;l++,t=1ll*t*T%Mod){
				int Nx=a[k+l],Ny=1ll*t*a[j+k+l]%Mod;
				a[k+l]=(Nx+Ny)%Mod;
				a[j+k+l]=(Nx-Ny+Mod)%Mod;
			}
		}
	}
	if(flag==-1){
		reverse(a+1,a+len);
		for(int i=0,t=quick_power(len,Mod-2,Mod);i<len;i++){
			a[i]=1ll*a[i]*t%Mod;
		}
	}
}
void calc_1(int l,int r){
	int cnt=1,limit=-1,mid=(l+r)>>1;
	while(cnt<=((r-l+1)<<1)){
		cnt<<=1;
		limit++;
	}
	for(int i=0;i<(cnt>>1);i++){
		p_0[i]=(i+l<=mid)?f_0[i+l]:0;
		p_1[i]=(i+l<=mid)?f_1[i+l]:0;
		tmp_g_0[i]=g_0[i];
		tmp_g_1[i]=g_1[i];
		tmp_g_2[i]=g_2[i];
	}
	for(int i=(cnt>>1);i<cnt;i++){
		tmp_g_0[i]=tmp_g_1[i]=tmp_g_2[i]=p_0[i]=p_1[i]=0;
	}
	NTT(tmp_g_0,1,cnt);
	NTT(tmp_g_1,1,cnt);
	NTT(tmp_g_2,1,cnt);
	NTT(p_0,1,cnt);
	NTT(p_1,1,cnt);
	for(int i=0;i<cnt;i++){
		tmp_1[i]=1ll*tmp_g_0[i]*p_0[i]%Mod;
		tmp_2[i]=1ll*tmp_g_1[i]*p_0[i]%Mod;
		tmp_3[i]=1ll*tmp_g_1[i]*p_1[i]%Mod;
		tmp_4[i]=1ll*tmp_g_2[i]*p_1[i]%Mod;
		tmp_g_0[i]=tmp_g_1[i]=tmp_g_2[i]=p_0[i]=p_1[i]=0;
	}
	NTT(tmp_1,-1,cnt);
	NTT(tmp_2,-1,cnt);
	NTT(tmp_3,-1,cnt);
	NTT(tmp_4,-1,cnt);
	for(int i=0;i<(cnt>>1);i++){
		if(i+l>=mid&&i+l<r){
			f_0[i+l+1]=(f_0[i+l+1]+tmp_1[i])%Mod;
			f_1[i+l+1]=(f_1[i+l+1]+tmp_2[i])%Mod;
		}
		if(i+l>=mid-2&&i+l<r-2){
			f_0[i+l+3]=(f_0[i+l+3]+tmp_3[i])%Mod;
			f_1[i+l+3]=(f_1[i+l+3]+tmp_4[i])%Mod;
		}
	}
}
void cdq_FFT_1(int l,int r){
	if(l==r){
		f_0[l]=(f_0[l]+g_0[l])%Mod;
		f_1[l]=(f_1[l]+g_1[l])%Mod;
		return;
	}
	int mid=(l+r)>>1;
	cdq_FFT_1(l,mid);
	calc_1(l,r);
	cdq_FFT_1(mid+1,r);
}
void calc_2(int l,int r){
	int cnt=1,limit=-1,mid=(l+r)>>1;
	while(cnt<=((r-l+1)<<1)){
		cnt<<=1;
		limit++;
	}
	for(int i=0;i<(cnt>>1);i++){
		p_0[i]=((i+l<=mid)?f_2[i+l]:0);
		tmp_g_2[i]=g_2[i];
		tmp_2[i]=0;
	}
	for(int i=(cnt>>1);i<cnt;i++){
		p_0[i]=tmp_g_2[i]=tmp_2[i]=0;
	}
	NTT(p_0,1,cnt);
	NTT(tmp_g_2,1,cnt);
	for(int i=0;i<cnt;i++){
		tmp_2[i]=1ll*p_0[i]*tmp_g_2[i]%Mod;
		p_0[i]=tmp_g_2[i]=0;
	}
	NTT(tmp_2,-1,cnt);
	for(int i=0;i<(cnt>>1);i++){
		if(i+l>=mid-2&&i+l<r-2){
			f_2[i+l+3]=(f_2[i+l+3]+tmp_2[i])%Mod;
		}
	}
}
void cdq_FFT_2(int l,int r){
	if(l==r){
		f_2[l]=((f_2[l]+g_2[l])%Mod+(l>0?tmp_1[l-1]:0))%Mod;
		return;
	}
	int mid=(l+r)>>1;
	cdq_FFT_2(l,mid);
	calc_2(l,r);
	cdq_FFT_2(mid+1,r);
}
int main(){
	scanf("%d",&x);
	g[0]=g[2]=1;
	for(int i=4;i<=x;i+=2){
		g[i]=(g[i-4]+g[i-2])%Mod;
	}
	for(int i=0;i<=x;i++){
		g_0[i]=1ll*g[i]*i%Mod*i%Mod;
		g_1[i]=1ll*g[i]*(i+1)%Mod*(i+1)%Mod;
		g_2[i]=1ll*g[i]*(i+2)%Mod*(i+2)%Mod;
	}
	cdq_FFT_1(0,x);
	while(cnt<=(x<<1)){
		cnt<<=1;
		limit++;
	}
	for(int i=0;i<cnt;i++){
		tmp_g_0[i]=(i<(cnt>>1)?f_1[i]:0);
		tmp_g_1[i]=(i<(cnt>>1)?g_1[i]:0);
		tmp_1[i]=0;
	}
	NTT(tmp_g_0,1,cnt);
	NTT(tmp_g_1,1,cnt);
	for(int i=0;i<cnt;i++){
		tmp_1[i]=1ll*tmp_g_0[i]*tmp_g_1[i]%Mod;
		tmp_g_0[i]=tmp_g_1[i]=0;
	}
	NTT(tmp_1,-1,cnt);
	cdq_FFT_2(0,x);
	ans=1ll*(g[x-1]+g[x-3])*(x-1)%Mod*(x-1)%Mod*x%Mod;
	for(int i=2;i<x-1;i++){
		ans=(ans+1ll*g_0[i-1]*f_0[x-i-1]%Mod*i)%Mod;
		ans=(ans+1ll*g_1[i-2]*f_1[x-i-2]%Mod*2*i)%Mod;
		if(i>2&&i<x-2){
			ans=(ans+1ll*g_2[i-3]*f_2[x-i-3]%Mod*i)%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}