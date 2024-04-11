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
int h,n;
// x taken from left
// y taken from down
int get(int x,int y){
	int num=(1LL<<(h-1));
	int f=num>>(h-y);
	return f+(x-1)*(1LL<<y);
}
pii find(int val){
	pii p={1,h};
    int num=(1LL<<(h-1));
    while(num!=val){
        if(val>num){
        	num=get(p.x*2,p.y-1);
        	p.x=p.x*2,p.y--;
        }
        else{
        	num=get(p.x*2-1,p.y-1);
        	p.x=p.x*2-1,p.y--;
        }
    }
    return p;
}
int solve(){
 cin>>n;
 int q;cin>>q;
 h=log2(n+1);
 rep3(q){
 	int u;string s;cin>>u>>s;
 	pii p=find(u);
 	for(auto i:s){
 		if(i=='U'){
 			if(p.y==h)continue;
 			p.x=(p.x+1)/2;
 			p.y++;
 		}
 		else if(i=='L'){
 			if(p.y==1)continue;
 			p.x=p.x*2-1;
 			p.y--;
 		}
 		else{
 			if(p.y==1)continue;
 			p.x=p.x*2;
 			p.y--;
 		}
 	}
 	cout<<get(p.x,p.y)<<endl;
 }
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}