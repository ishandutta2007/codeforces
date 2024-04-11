// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 4e6 + 5;
int t[N];
int lazy[N];



int solve(){
 

		int n,m; cin >> n >> m;


		vector<pair<int,pair<int,int>>> segments(n);
		for(auto &i:segments){
			cin >> i.second.first >> i.second.second >> i.first;
			if(i.second.second < m){
				i.second.second--;
			}
		}
		int l,r,val;
		auto pushdown = [&](int v){
			lazy[2*v] += lazy[v];
			lazy[2*v + 1] += lazy[v];
		};

		function<void(int,int,int)>update = [&](int v,int tl,int tr){
			if(lazy[v]){
				t[v] += lazy[v];
				if(tl != tr){
					pushdown(v);
				}
				lazy[v] = 0;
			}
			if(l > tr or tl > r)return;
			if(l <= tl and tr <= r){
				lazy[v] = val;
				t[v] += val;
				if(tl != tr){
					pushdown(v);
				}
				lazy[v] = 0;
				return;
			}
			int mid = (tl + tr)/2;
			update(2*v,tl,mid);
			update(2*v + 1,mid + 1,tr);
			t[v] = min(t[2*v],t[2*v + 1]);
		};

		function<int(int,int,int)>query = [&](int v,int tl,int tr){
			if(lazy[v]){
				t[v] += lazy[v];
				if(tl != tr){
					pushdown(v);
				}
				lazy[v] = 0;
			}
			if(l > tr or tl > r)return LLONG_MAX;
			if(l <= tl and tr <= r){
				return t[v];
			}
			int mid = (tl + tr)/2;
			int a = query(2*v,tl,mid);
			int b = query(2*v + 1,mid + 1,tr);
			return min(a,b);
		};	


		sort(segments.begin(),segments.end());
		
		int j = 0;
		int ans = 1e9;
		for(int i = 0; i < n; i++){
			while(j < n){
				l = 1, r = m;
				if(query(1,1,m) > 0)break;
				l = segments[j].y.x;
				r = segments[j].y.y;
				val = 1;
				update(1,1,m);
				j++;
			}
			l = 1, r = m;
			if(query(1,1,m) > 0){
				mins(ans,segments[j - 1].x - segments[i].x);
			}else{
				break;
			}
			l = segments[i].y.x;
			r = segments[i].y.y;
			val = -1;
			update(1,1,m);
		}


		cout << ans << endl;

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