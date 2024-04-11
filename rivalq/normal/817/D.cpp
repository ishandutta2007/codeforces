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
int func(vector<int>&v){
	int n=sz(v)-1;
	stack<pii>st;
	vector<int>left(n+1),right(n+1);
	for(int i=1;i<=n;i++){
		while(!st.empty() && st.top().x<=v[i]){
			right[st.top().y]=i;
			st.pop();
		}
		st.push({v[i],i});
	}
	while(!st.empty()){
		right[st.top().y]=n+1;
		st.pop();
	}
	for(int i=n;i>=1;i--){
		while(!st.empty() && st.top().x<v[i]){
			left[st.top().y]=i;
			st.pop();
		}
		st.push({v[i],i});
	}
	while(!st.empty()){
		left[st.top().y]=0;
		st.pop();
	}
    int ans=0;
    for(int i=1;i<=n;i++){
    	int l=left[i]+1;
    	int r=right[i]-1;
    	//cout<<l<<" "<<r<<endl;
    	l=i-l;
    	r=r-i;
    	ans+=v[i]*(1+l+r+l*r);
    }
    return ans;
}

int solve(){
 int n;cin>>n;
 vector<int>v1(n+1),v2(n+1);
 rep(i,1,n+1){
 	cin>>v1[i];
 	v2[i]=-v1[i];
 }
 cout<<func(v1)+func(v2)<<endl;
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