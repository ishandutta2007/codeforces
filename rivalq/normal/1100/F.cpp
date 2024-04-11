#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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

const int N=5e5+5;

int a[N];
int ans[N];
set<pii>st[N];

void insert(vector<int>&dp,int mask){
	for (int i=19;i>=0;i--) {
		if ((mask & 1 << i)==0)continue;
		if(!dp[i]){
			dp[i]=mask;
			return;
		}
		mask ^= dp[i];
	}

}

int query(vector<int>&dp1,vector<int>&dp2){
	vector<int> res=dp1;
	for (int i=19;i>=0;i--) {
		insert(res,dp2[i]);
	}
	int ans = 0;
	for (int i=19;i>=0;i--) {
		if (!res[i]) continue;
		if (ans & 1 << i) continue;
		ans ^= res[i];
	}

	return ans;
}


void dfs(int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	int n1=mid-l+1;
	int n2=r-mid;
	vector<vector<int>>dp1(n1+1,vector<int>(22,0)),dp2(n2+2,vector<int>(22,0));
	for(int i=mid,cnt=1;i>=l;i--,cnt++){
		dp1[cnt]=dp1[cnt-1];
		insert(dp1[cnt],a[i]);
	}
	for(int i=mid+1,cnt=1;i<=r;i++,cnt++){
		dp2[cnt]=dp2[cnt-1];
		insert(dp2[cnt],a[i]);
	}
	
	for(int i=mid,cnt=1;i>=l;i--,cnt++){
		while(st[i].size()>0){
			auto s=st[i].upper_bound({mid,0});
			if(s==st[i].end())break;
			int r=s->x-mid;
			//cout<<s->x-mid<<" "<<s->y<<endl;
			ans[s->y]=query(dp1[cnt],dp2[r]);
			st[i].erase(s);
		}
	}
	
	dfs(l,mid);
	dfs(mid+1,r);
}


int solve(){
 	int n;cin>>n;
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	int q;cin>>q;
 	rep(i,1,q+1){
 		int l,r;cin>>l>>r;
 		if(l==r){
 			ans[i]=a[l];
 		}
 		else{
 			st[l].insert({r,i});
 		}
 	}
 	dfs(1,n);
 	rep(i,1,q+1)cout<<ans[i]<<endl;
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