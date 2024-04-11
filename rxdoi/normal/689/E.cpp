#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define Rep(x,a,b) for (int x=a;x<=(int)b;x++)
#define Drp(x,a,b) for (int x=a;x>=(int)b;x--)
#define Cross(x,a) for (int x=Hd[a];~x;x=Nx[x])
#define ll long long
#define INF (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fr first
#define sc second
#define MOD 1000000007
using namespace std;
inline ll Rd(){
	ll x=0;int ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void Rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) Rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
const int N=200005;
int l[N],r[N],Ls[N<<1],Cnt,n,k;
int QPow(int Ds,int Zs){
	if (Zs==0) return 1;
	int Ret=QPow(Ds,Zs/2);
	if (Zs&1) return 1ll*Ret*Ret%MOD*Ds%MOD;
		else return 1ll*Ret*Ret%MOD;
}
int Pls[N<<3];
void Add(int i,int l,int r,int Fr,int Bh){
	if (l==Fr&&r==Bh){
		Pls[i]++;
		return;
	}
	int mid=l+r>>1;
	if (Bh<=mid) Add(i<<1,l,mid,Fr,Bh);
	else if (Fr>mid) Add(i<<1|1,mid+1,r,Fr,Bh);
	else Add(i<<1,l,mid,Fr,mid),Add(i<<1|1,mid+1,r,mid+1,Bh);
}
int Jc[N],Ny[N],Ans;
int C(int n,int m){
	return 1ll*Jc[n]*Ny[m]%MOD*Ny[n-m]%MOD;
}
void CalcAns(int i,int l,int r){
	if (l>r) return;
	if (l==r){if (Pls[i]>=k) (Ans+=1ll*C(Pls[i],k)*(Ls[l+1]-Ls[l])%MOD)%=MOD;return;}
	Pls[i<<1]+=Pls[i],Pls[i<<1|1]+=Pls[i];
	int mid=l+r>>1;
	CalcAns(i<<1,l,mid),CalcAns(i<<1|1,mid+1,r);
}
int main(){
	n=Rd(),k=Rd();
	Jc[0]=1;Rep(i,1,n) Jc[i]=1ll*Jc[i-1]*i%MOD;
	Ny[n]=QPow(Jc[n],MOD-2);
	Drp(i,n-1,0) Ny[i]=1ll*Ny[i+1]*(i+1)%MOD;
	Rep(i,1,n) l[i]=Rd(),r[i]=Rd()+1;
	Rep(i,1,n) Ls[++Cnt]=l[i],Ls[++Cnt]=r[i];
	sort(Ls+1,Ls+Cnt+1);
	Cnt=unique(Ls+1,Ls+Cnt+1)-Ls-1;
	Rep(i,1,n) l[i]=lower_bound(Ls+1,Ls+Cnt+1,l[i])-Ls;
	Rep(i,1,n) r[i]=lower_bound(Ls+1,Ls+Cnt+1,r[i])-Ls;
	Rep(i,1,n) Add(1,1,Cnt,l[i],r[i]-1);
	CalcAns(1,1,Cnt);
	Rt(Ans);
}