#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

priority_queue<pii> q1;
priority_queue<int> q2;
int n,cnt,a[N],b[N];
ll ans;
int rem(){
	int L=-inf,R=-inf;
	if(!q1.empty()) L=q1.top().FF;
	if(!q2.empty()) R=q2.top();
	if(L>R){
		q2.push(b[q1.top().SS]);
		q1.pop();return L;
	}
	q2.pop();return R;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a1,b1,a2,b2;
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		a[i]=a1+b1;b[i]=a2+b2;
		if(a[i]>b[i]) cnt++,q1.push(mp(a[i],i)),ans-=b1+b2;
		else if(b1+b2>max(a[i],b[i])) ans-=b1+b2-max(a[i],b[i]);
		else if(b1+b2<min(a[i],b[i])) ans+=min(a[i],b[i])-b1-b2;
	}
	for(int i=1;i<=cnt;i++)
		ans+=rem(),rem();
	printf("%I64d\n",ans);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}