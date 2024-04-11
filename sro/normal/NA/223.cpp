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

int n,m,k;
const int Maxm=1<<19;
char s[Maxm],t[Maxm];
int a[Maxm],b[Maxm];
int can[Maxm];
char ch[]="GCAT";
int ho[Maxm];
const int jt=998244353,rg=3;

int inline ksmii(int a,int b){
	if(!b)return 1;
	int x=ksmii(a,b>>1);
	x=1ll*x*x%jt;
	if(b&1)x=1ll*x*a%jt;
	return x;
}

void fft(int a[],int inv){
	loop(i,Maxm)ho[i]=((ho[i>>1]>>1)|((i&1)<<18));
	loop(i,Maxm)if(i<ho[i])swap(a[i],a[ho[i]]);
	range(i,1,Maxm-1,i){
		int omega=ksmii(rg,inv*(jt-1)/(i<<1)+jt-1);
		range(j,0,Maxm-1,i<<1){
			int omg=1;
			loop(k,i){
				int x=a[j+k],y=1ll*omg*a[j+k+i]%jt;
				a[j+k]=(x+y)%jt;
				a[j+k+i]=(x-y+jt)%jt;
				omg=1ll*omg*omega%jt;
			}
		}
	}
	if(inv==-1){
		int fn=ksmii(Maxm,jt-2);
		loop(i,Maxm)a[i]=1ll*a[i]*fn%jt;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s,t);
	reverse(t,t+m);
	loop(i,Maxm)can[i]=1;
	loop(c,4){
		int sum=0;
		memset(b,0,sizeof(b));
		loop(i,m)b[i]=(t[i]==ch[c]),sum+=b[i];
		vector<int> as;
		loop(i,n)if(s[i]==ch[c])as.pub(i);as.pub(Inf);
		memset(a,0,sizeof(a));
		loop(i,n)if(*lower_bound(all(as),i-k)<=i+k)a[i]=1;
		fft(a,1);fft(b,1);
		loop(i,Maxm)a[i]=1ll*a[i]*b[i]%jt;
		fft(a,-1);
		loop(i,Maxm)if(a[i]!=sum)can[i]=0;
	}
	int res=0;
	loop(i,Maxm)res+=can[i];
	printf("%d\n",res);
	return 0;
}