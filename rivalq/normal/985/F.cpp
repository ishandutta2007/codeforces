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

const int N = 2e5+5;
typedef unsigned long long ull;

int gen_base(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed ^ ull(new ull));
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

int MOD = gen_base(hell,2147483647);
int base = gen_base(3000,6000);

int pre[N];

int solve(){
		//cout<<base<<" "<<MOD<<endl;
		int n,m;cin>>n>>m;
		vector<int>vec[26];
		rep(j,0,26){
			vec[j].resize(n+1,0);
		} 
		vector<char>a(n+1);
		pre[0]=0;
		int val=1;
		rep(i,1,n+1){
			pre[i]=(val)%MOD;
			val=val*base%MOD;
		}
		rep(i,1,n+1){
			cin>>a[i];
			rep(j,0,26){
				vec[j][i]=vec[j][i-1];
			}
			vec[a[i]-97][i]+=pre[i];
			vec[a[i]-97][i]%=MOD;
		}
		rep(i,0,m){
			int p,q,len;cin>>p>>q>>len;
			multiset<int>s1,s2;
			if(p>q)swap(p,q);
			int adjust=pre[q-p+1];
			rep(j,0,26){
				int l=p,r=p+len-1;
				int hash_cur=(vec[j][r]-vec[j][l-1]+MOD)%MOD;
				hash_cur=hash_cur*adjust%MOD;
				s1.insert(hash_cur);
				l=q,r=q+len-1;
				hash_cur=(vec[j][r]-vec[j][l-1]+MOD)%MOD;
				s2.insert(hash_cur);
			}
			if(s1==s2){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
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