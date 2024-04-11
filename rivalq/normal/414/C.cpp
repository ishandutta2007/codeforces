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

const int N=(1<<20)+5;

int inv[21];
int t[21];
int a[N];


int dc(int l,int r,int k){
	if(l==r){
		return 0;
	}
	int mid=(l+r)/2;
	dc(l,mid,k-1);
	dc(mid+1,r,k-1);
	vector<pii>vec;
	int i=l,j=mid+1;
	while(i<=mid && j<=r){
		if(a[i]<=a[j]){
			vec.pb({a[i++],1});
		}
		else{
			vec.pb({a[j++],0});
		}
	}
	while(i<=mid)vec.pb({a[i++],1});
	while(j<=r)vec.pb({a[j++],0});
	int cnt=mid-l+1;
	int c=l;
	for(auto j:vec){
		if(!j.y)inv[k]+=cnt;
		cnt-=j.y;
	}
	vec.clear();
	i=l,j=mid+1;
	while(i<=mid && j<=r){
		if(a[j]<=a[i]){
			vec.pb({a[j++],1});
		}
		else{
			vec.pb({a[i++],0});
		}
	}
	while(j<=r)vec.pb({a[j++],1});
	while(i<=mid)vec.pb({a[i++],0});
	cnt=r-mid;
	c=l;
	for(auto j:vec){
		a[c++]=j.x;
		if(!j.y)t[k]+=cnt;
		else cnt--;
	}
	return 0;
}


int solve(){
 	int n;cin>>n;
 	int m=(1<<n);
 	rep(i,1,m+1){
 		cin>>a[i];
 	}
 	dc(1,m,n);
 	//rep(i,1,m+1){
 	//	cout<<a[i]<<" ";
 	//}cout<<endl;
 	int q;cin>>q;
 	//rep(i,0,n+1)cout<<t[i]<<" ";cout<<endl;
 	//rep(i,0,n+1)cout<<inv[i]<<" ";cout<<endl;
 	rep3(q){
 		int k;cin>>k;
 		
 		for(int i=k;i>=0;i--){
 			swap(inv[i],t[i]);
 		}
 		int ans=0;
 		for(int i=0;i<=n;i++){
 			ans+=inv[i];
 		}//cout<<endl;
 		cout<<ans<<endl;
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