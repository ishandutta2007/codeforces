#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
void generate(vector<int> &v,int st,int en,int a,int x){
	int l=st;
	int c=st;
	int r=st+a-1;
	for(int j=0;j<x;j++){
		v[r]=c;
		int f=c+1;
		for(int i=l;i<r;i++,f++)v[i]=f;
		c+=a;
		l+=a;
		r+=a;	
	}
}
int solve(){
 int n,a,b;cin>>n>>a>>b;
 if(a==1 || b==1){
 	rep3(n)cout<<i+1<<" ";cout<<endl;return 0;
 }
 int t=n;
 int x1=0,x2=0;
 while(t>0){
     if(t%b==0){
     	x2=t/b;
     	break; 
     }
     else{
     	t-=a;
        x1++;
        if(t<0){
        	cout<<-1<<endl;return 0;
        }
     }
 }
 vector<int>v(n+1,0);
 int st=1,en=x1*a;
 generate(v,st,en,a,x1);
 st=en+1;
 en=n;
 generate(v,st,en,b,x2);
 for(int i=1;i<=n;i++)cout<<v[i]<<" ";cout<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}