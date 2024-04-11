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
pii func(int a,int b){
	if(a==0)return {0,1};
	if(b==0)return {1,0};
	int g=gcd(a,b);
	return {a/g,b/g};
}
bool func2(int i,int j,int k,vector<pii>v){
	 pii p=func(v[i].y-v[j].y,v[i].x-v[j].x);
	 pii temp2=func(v[i].y-v[k].y,v[i].x-v[k].x);
	 map<pii,int>mp;
	 bool found =0;
	 pii p2;
     if(p!=temp2){
	 	found=1;
	 	p2=v[k];
	 }
	 for(int l=3;l<sz(v);l++){
	 	pii temp=func(v[i].y-v[l].y,v[i].x-v[l].x);
	 	if(temp==p)continue;
	 	if(found==0){
	 		found=1;
	 		p2=v[l];
	 		continue;
	 	}
	 	temp=func(v[l].y-p2.y,v[l].x-p2.x);
	 	mp[temp]++;
	 }
	 return sz(mp)<=1;
}
int solve(){
 int n;cin>>n;
 vector<pii>v(n);
 rep3(n)cin>>v[i];
 if(n<=4){
 	cout<<"YES"<<endl;exit(0);
 }
 bool f=func2(0,1,2,v)|func2(0,2,1,v)|func2(1,2,0,v);
 if(f)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
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