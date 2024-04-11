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

int n;
int a[1<<17];
vector<int> ins[1<<17];
const int jt=1000000007;

int inline ksmii(int a,int b){
	if(!b)return 1;
	int x=ksmii(a,b>>1);
	x=1ll*x*x%jt;
	if(b&1)x=1ll*x*a%jt;
	return x;
}

int main(){
	scanf("%d",&n);
	cont(i,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	cont(i,a[n])range(j,i,a[n],i)ins[j].pub(i);
	int ans=0;
	cont(i,a[n]){
		int lst=1,res=1;
		cont(j,ins[i].size()-1){
			int now=lower_bound(a+1,a+n+1,ins[i][j])-a;
			res=1ll*res*ksmii(j,now-lst)%jt;lst=now;
		}
		res=1ll*res*(ksmii(ins[i].size(),n+1-lst)-ksmii(ins[i].size()-1,n+1-lst)+jt)%jt;
		(ans+=res)%=jt;
	}
	printf("%d\n",ans);
	return 0;
}