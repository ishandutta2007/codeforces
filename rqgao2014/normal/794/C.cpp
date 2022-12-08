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

const int N=300005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

char s[N],t[N],ans[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%s",s+1);scanf("%s",t+1);
	int k=strlen(s+1);
	sort(s+1,s+k+1);
	sort(t+1,t+k+1);
	reverse(t+1,t+k+1);
	int n=(k+1)/2,m=k/2,al=1,ar=n,bl=1,br=m,l=1,r=k;
	for(int i=1;i<=k;i++){
		if(i&1){
			if(s[al]<t[bl]) ans[l++]=s[al++]; else ans[r--]=s[ar--];
		}
		else{
			if(t[bl]>s[al]) ans[l++]=t[bl++]; else ans[r--]=t[br--];
		}
	}
	printf("%s\n",ans+1);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}