#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int P=1051131;
const int ny=525566;
const int N=(1<<25)+233;
int ST;
int A[N*2],ans[N],p[26],q[26];int tot;
int m,s,n;LL t;
inline int Pow(int a,LL b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
void Do(int k){
	int st=tot;
	tot+=(1<<k);
	if(k==0){
		ans[1]=Pow(p[k]+q[k],t);
		ans[1]=ans[1]*1ll*A[st+1]%P;
		return;
	}
	
	int nst=tot;
	rep(i,1,(1<<(k-1))){
		A[nst+i]=(A[st+i]+A[st+i+(1<<(k-1))])%P;
	}
	
	p[k-1]=2ll*p[k]%P;
	
	q[k-1]=(1<<(k-1))*1ll*p[k]%P;
	q[k-1]=(q[k-1]-p[k]+q[k])%P;
	
	Do(k-1);
	
	int bo=-(1<<(k-1));
	bo=bo*1ll*p[k]%P;
	bo=(bo+p[k]+q[k])%P;
	bo=Pow(bo,t);
	rep(i,1,1<<(k-1)){
		ans[i+(1<<(k-1))]=ans[i];
		ans[i]=(ans[i]+(A[st+i]-A[st+i+(1<<(k-1))])*1ll*bo)%P;
		ans[i+(1<<(k-1))]=(ans[i+(1<<(k-1))]-(A[st+i]-A[st+i+(1<<(k-1))])*1ll*bo)%P;
	}
	
	rep(i,1,(1<<k))ans[i]=ans[i]*1ll*ny%P;
}
int ED;
int main(){
	scanf("%d%I64d%d",&m,&t,&s);
	n=(1<<m);
	rep(i,1,n){
		if(i<=s)scanf("%d",&A[i]);
		else{
			A[i]=(A[i-s]*101+10007)%P;
		}
	}
	p[m]=1;q[m]=0;
	Do(m);
	int rp=0;
	rep(i,1,n){
		if(ans[i]<0)ans[i]+=P;
		rp^=ans[i];
	}
	printf("%d\n",rp);
	//printf("%d\n",(&ED)-(&ST));
	return 0;
}