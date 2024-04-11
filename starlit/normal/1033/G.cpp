#include<bits/stdc++.h>
const int N=302;
#define fi first
#define se second
using namespace std;
typedef long long ll;
ll V[N],F,S,X;
int n,m,t,tp,v[N],le[N],ls,lk,f[4],i;
inline int cal(int x,int y){
	x=v[x];
	return x<y?0:(x<i-y?1:(2|(x>=y<<1)));
}
pair<int,int> a[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%lld",V+i);
	for(i=2;i<=m<<1;i++){
		f[0]=f[1]=f[2]=f[3]=0;
		for(int j=t=tp=0;j<n;j++)
		v[j]=V[j]%i,a[t++]={v[j]+1,j},a[t++]={(v[j]>>1)+1,j},
		a[t++]={i-v[j],j},tp+=v[j]/(i>>1);
		a[t++]={i+1>>1,0};
		if(i&1^1)tp&1?++F:++S;
		sort(a,a+t),lk=ls=max(i-m,1);
		if(ls<<1>=i)continue;
		for(int j=0;j<n;j++)f[cal(j,le[j]=ls)]++;
		for(int j=0;j<t;j++){
			if(a[j].fi<=lk)continue;
			if((tp=a[j].fi-ls)&&!f[1]&&f[3]<2)
			(f[2]+f[3]&1)?F+=tp<<1:(f[3]?0:S+=tp<<1);
			if(a[j].fi<<1>=i)break;
			ls=a[j].fi;
			f[cal(a[j].se,le[a[j].se])]--,
			f[cal(a[j].se,le[a[j].se]=ls)]++;
		}
	}X=1ll*m*m-F-S>>1;
	printf("%lld %lld %lld %lld",X,X,F,S);
}