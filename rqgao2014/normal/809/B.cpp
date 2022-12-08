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
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,k;

bool get(int l,int r){
	string fed;
	cout<<"1 "<<l<<" "<<r<<endl;
	fflush(stdout);
	cin>>fed;
	return fed[0]=='T';
}
int solve(int l,int r){
	if(l>r) return 0;
	if(l==r) return r;
	int mid=l+r>>1;
	if(get(mid,mid+1)) return solve(l,mid);
	return solve(mid+1,r);
}

int main(){
	cin>>n>>k;
	int a=solve(1,n);
	int b=solve(1,a-1),c=solve(a+1,n);
	if(!b||!c) cout<<"2 "<<(b|c)<<" "<<a<<endl;
	else if(get(b,c)) cout<<"2 "<<b<<" "<<a<<endl;
	else cout<<"2 "<<c<<" "<<a<<endl;
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}