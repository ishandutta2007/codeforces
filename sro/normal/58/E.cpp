/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int a,b,c;
ll ra,rb,rans=20;
ll mii[20];

void dfs(ll a,ll b,ll c,ll as,ll bs,int jw,int ws,int len){
	if(len>=rans)return;
	if(!a&&!b&&!c&&!jw){
		rans=len;
		ra=as;rb=bs;
		return;
	}
	if(!c){
		ll num=a+b+jw;
		int weis=0;
		while(num)num/=10,weis++;
		dfs(0,0,0,as+mii[ws]*a,bs+mii[ws]*b,0,ws,len+weis);
	}else if((a+b+jw)%10==c%10){
		dfs(a/10,b/10,c/10,as+mii[ws]*(a%10),bs+mii[ws]*(b%10),(a%10+b%10+jw)/10,ws+1,len);
	}else{
		dfs(a*10+(c-b%10-jw+10)%10,b,c,as,bs,jw,ws,len+1);
		dfs(a,b*10+(c-a%10-jw+10)%10,c,as,bs,jw,ws,len+1);
		dfs(a,b,c*10+(a+b+jw)%10,as,bs,jw,ws,len+1);
	}
}

int main(){
	scanf("%d+%d=%d",&a,&b,&c);
	mii[0]=1;cont(i,19)mii[i]=mii[i-1]*10;
	dfs(a,b,c,0,0,0,0,0);
	printf("%lld+%lld=%lld\n",ra,rb,ra+rb);
	return 0;
}