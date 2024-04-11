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

const int jt=998244353;
int n,m;
int jc[1<<19],fjc[1<<19];
int l[1<<19],r[1<<19];
int a[44],b[44];
int xf[1<<19],cs[1<<19][44];
int lgl[1<<19];

int ksmii(int a,int b){
	if(!b)return 1;
	int x=ksmii(a,b>>1);
	x=1ll*x*x%jt;
	if(b&1)x=1ll*x*a%jt;
	return x;
}

int inline C(int a,int b){
	if(b<0||a<b)return 0;
	return 1ll*jc[a]*fjc[b]%jt*fjc[a-b]%jt;
}

int main(){
	jc[0]=1;cont(i,500000)jc[i]=1ll*jc[i-1]*i%jt;
	fjc[500000]=ksmii(jc[500000],jt-2);range(i,500000,1,-1)fjc[i-1]=1ll*fjc[i]*i%jt;
	scanf("%d%d",&n,&m);
	cont(i,n){
		scanf("%d%d",l+i,r+i);
		xf[l[i]]++;xf[r[i]+1]--;
	}
	cont(i,n){
		xf[i]+=xf[i-1];
		loop(j,m<<1|1){
			cs[i][j]=(cs[i-1][j]+C(xf[i]-j,i-j))%jt;
		}
	}
	loop(i,m)scanf("%d%d",a+i,b+i);
	int ans=0;
	loop(i,1<<m){
		int ls=1,rs=n,ts=0;
		loop(j,m){
			if(!((i>>j)&1))continue;
			if(lgl[a[j]]!=i){
				lgl[a[j]]=i;
				ts++;
			}
			if(lgl[b[j]]!=i){
				lgl[b[j]]=i;
				ts++;
			}
			ls=max(ls,max(l[a[j]],l[b[j]]));
			rs=min(rs,min(r[a[j]],r[b[j]]));
		}
		if(ls>rs)continue;
		int res=(cs[rs][ts]-cs[ls-1][ts]+jt)%jt;
		if(__builtin_popcount(i)%2)ans=(ans-res+jt)%jt;
		else ans=(ans+res)%jt;
	}
	printf("%d\n",ans);
	return 0;
}