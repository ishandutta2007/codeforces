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
struct seg{
	int x1,y1,x2,y2;
	seg(int x0,int y0,int x01,int y01){
		x1=min(x0,x01);
		x2=x01+x0-x1;
		y1=min(y0,y01);
		y2=y0+y01-y1;
	}
    int d(){
    	return abs(x1-x2)+abs(y1-y2);
    }
    int isp(){
    	return (x1!=x2 && y1!=y2);
    }
    int ispoint(){
    	return (x1==x2 && y1==y2);
    }
    int dis(seg s){
        if(y1==y2)return abs(y1-s.y1);
        return abs(x1-s.x1);
    }
};

int solve(){
 vector<seg>v;
 vector<seg>v1,v2;	
 int d1,d2;
 rep3(4){
 	int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
 	v.pb(seg(x1,y1,x2,y2));
 	if(v[i].ispoint() || (v[i].isp())){
 		cout<<"NO"<<endl;exit(0);
 	}
 	if(x1==x2)v1.pb(v[i]),d1=v[i].d();
 	else v2.pb(v[i]),d2=v[i].d();
 }
 if(sz(v1)<2 || sz(v2)<2){
 	cout<<"NO"<<endl;exit(0);
 }
 if(v1[0].d()!=v1[1].d()){
 	cout<<"NO"<<endl;exit(0);
 }
 if(v2[0].d()!=v2[1].d()){
 	cout<<"NO"<<endl;exit(0);
 }
 if(d2!=v1[0].dis(v1[1]) || d1!=v2[0].dis(v2[1])){
 	cout<<"NO"<<endl;exit(0);
 }
 cout<<"YES"<<endl;
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