#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e4+5;
const int mo = 1e9+7;

LL n;
int k;
int tim[1000];
LL pri[1000];
int u;
LL inv[N*2];
LL Ny[N*2];

LL f[N][60];

int main(){
	inv[0]=inv[1]=1;
	fo(i,2,2e4)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,0,2e4)Ny[i]=inv[i];
	fo(i,2,2e4)inv[i]=inv[i]*inv[i-1]%mo;
	cin>>n>>k;
	int lim=sqrt(n);
	u=0;
	LL x=n;
	fo(i,2,lim)
	if (x%i==0){
		pri[++u]=i;
		for(;x%i==0;x/=i)tim[u]++;
	}
	if (x>1){
		pri[++u]=x;
		tim[u]=1;
	}
	LL ans=1;
	fo(t,1,u){
		LL x=pri[t];
		int up=tim[t];
		fo(i,0,k)fo(j,0,up)f[i][j]=0;
		f[0][up]=1;
		fo(i,0,k-1)
			fo(j,0,up){
				LL tmp=f[i][j]*Ny[j+1]%mo;
				fo(d,0,j)f[i+1][d]=(f[i+1][d]+tmp)%mo;
			}
		LL val=0;
		for(LL pdt=1,i=0;i<=up;i++,pdt=pdt*x%mo)val=(val+pdt*f[k][i])%mo;
		ans=ans*val%mo;
	}
	cout<<ans<<endl;
	return 0;
}