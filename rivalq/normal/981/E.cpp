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

const int maxn=1e4+5;

bitset<maxn> ans;
vector<int>t[4*maxn];

void add_line(int v,int tl,int tr,int l,int r,int val){
	if(l>tr || tl>r)return;
	if(l<=tl && tr<=r){
		t[v].pb(val);
		return ;
	}
	int mid=(tl+tr)/2;
	add_line(2*v,tl,mid,l,r,val);
	add_line(2*v+1,mid+1,tr,l,r,val);
}

void dfs(int v,int tl,int tr,bitset<maxn> kn){
	bitset<maxn>temp=kn;
	for(auto i:t[v]){
		temp|=(temp<<i);
	}
	if(tl==tr){
		ans|=temp;
		return;
	}
	int mid=(tl+tr)/2;
	dfs(2*v,tl,mid,temp);
	dfs(2*v+1,mid+1,tr,temp);
}

int solve(){
 	int n,q;cin>>n>>q;
 	rep(i,1,q+1){
 		int l,r,x;cin>>l>>r>>x;
 		add_line(1,1,n,l,r,x);
 	}
 	bitset<maxn> st;
 	st[0]=1;
 	dfs(1,1,n,st);
 	int cnt=0;
 	for(int i=1;i<=n;i++){
 		if(ans[i])cnt++;
 	}
 	cout<<cnt<<endl;
 	for(int i=1;i<=n;i++){
 		if(ans[i]){
 			cout<<i<<" ";
 		}
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