#include <bits/stdc++.h>

using namespace std;

#define MOD (1000*1000*1000+7)
#define MAXN (2000*100+228)

typedef long long ll;

/*--------------------------------------------IO_Methods--------------------------------------------*/
inline void print(int a){printf("%d ",a);}
inline void print(ll a){printf("%ld ",a);}
inline void print(){printf("\n");}
inline void print(vector<int> a){for(int i=0;i<a.size();i++){print(a[i]);}print();}
inline void print(vector<ll> a){for(int i=0;i<a.size();i++){print(a[i]);}print();}
inline int scani(){int a;scanf("%d",&a);return a;}
inline ll scanl(){ll a;scanf("%ld",&a);return a;}
/*-----------------------------------------------MATHS----------------------------------------------*/
inline int gcd(int a,int b){int tmp;while(b){a=a%b;tmp=a;a=b;b=tmp;}return a;}
inline ll gcd(ll a,ll b){ll tmp;while(b){a=a%b;tmp=a;a=b;b=tmp;}return a;}
inline int lcm(int a,int b){return a*b/gcd(a,b);}
inline ll lcm(ll a,ll b){return a*b/gcd(a,b);}
inline int pom(int x,int pow,int mod){if(x==1){return x;}else if(pow&1){return (x*pom(x,pow-1,mod)%mod);}else{ll tmp=pom(x,pow/2,mod);return (tmp*tmp)%mod;}}
inline ll pom(ll x,ll pow,ll mod){if(x==1){return x;}else if(pow&1){return (x*pom(x,pow-1,mod)%mod);}else{ll tmp=pom(x,pow/2,mod);return (tmp*tmp)%mod;}}
/*-------------------------------------------------------------------------------------------------*/
int main(){
	#ifdef SendThemToHell
		freopen("in.txt","r",stdin);
	#endif
	ll n,m,k,x,s;
	cin>>n>>m>>k>>x>>s;
	ll a1[MAXN],a2[MAXN],b1[MAXN],b2[MAXN];
	for(int i=0;i<m;i++)cin>>a1[i];
	for(int i=0;i<m;i++)cin>>a2[i];
	for(int i=0;i<k;i++)cin>>b1[i];
	for(int i=0;i<k;i++)cin>>b2[i];
	m++;
	a1[m-1]=x;a2[m-1]=0;
	ll ans=x*n;
	for(int i=0;i<m;i++){
		ll sn=s-a2[i],xn=a1[i],pa=0;
		if(b2[0]<=sn){
			int left=0,right=k;
			while(right-left>1){
				int mid=(right+left)/2;
				if(b2[mid]<=sn)
					left=mid;
				else
					right=mid;
			}
			pa=b1[left];
		}
		
		if(ans>xn*(n-pa) && sn>=0)
			ans=max(xn*(n-pa),(ll)0);
	}
	cout<<ans<<endl;
	return 0;
}