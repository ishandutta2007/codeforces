#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=10050000;
int pr[N];
int q[N];
bool is[N];
int n;
int miu[N];
LL t[N];
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		if(!is[i]){
			pr[i]=i;
			q[++q[0]]=i;
		}
		for(int j=1;j<=q[0]&&q[j]*i<=n;j++){
			is[q[j]*i]=1;
			pr[q[j]*i]=q[j];
			if(i%q[j]==0)break;
		}
	}
	miu[1]=1;
	rep(i,2,n){
		if((i/pr[i])%pr[i]==0)miu[i]=0;
		else miu[i]=-miu[i/pr[i]];
	}
	LL ans=0;

	int he=0;
	rep(i,2,n)if(is[i])++he;


	rep(d,2,n)ans+=miu[d]*((n/d-(!is[d]))*1ll*(n/d-(!is[d])));
	ans+=he*1ll*he;

	ans/=2;

	//cout<<ans<<endl;
	//cout<<he<<endl;
	ans=(he*1ll*(he-1)/2-ans)*1+ans*2;
	
	//cout<<ans<<endl;

	LL w=0;
	int s=q[0];
	int zb=q[0];
	while(q[zb]>n/2&&zb)--zb;
	s=zb;
	rep(i,1,zb){
		while(s&&q[s]*1ll*q[i]>n)--s;
		w+=s*2+(zb-s)*3;
		if(i<=s)w-=2;
		else w-=3;
	}
	w/=2;
	ans+=w;

	//cout<<ans<<endl;
	
	w=0;
	rep(i,1,zb)w+=(n/q[i]-1);

	s=zb;
	rep(i,2,n)if(!is[i]){
		while(s&&q[s]*1ll*i>n)--s;
		//cout<<i<<" "<<s<<" "<<zb<<endl;
		t[i]=s*2+(zb-s)*3;
	}
	//cout<<w<<endl;
	rep(i,2,n)if(is[i]){
		w+=t[pr[i]];
		//cout<<i<<" "<<w<<endl;
		int x=i;
		while(x!=1){
			if(pr[x]<=n/2){
				if(pr[x]*1ll*pr[i]<=n)w-=2;
				else w-=3;
			}
			int d=pr[x];
			while(x%d==0)x/=d;
		}
	}
	ans+=w;
	printf("%lld\n",ans);
	return 0;
}