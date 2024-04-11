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

const int N=2000;

double dp[N][N][2];
bool vis[N][N][2];

double zeno(int i,int j,int f){
	if(i==0)return 0;
	if(vis[i][j][f])return dp[i][j][f];
	vis[i][j][f]=1;
	if(f){
		if(j==0){
			return dp[i][j][1]=1;
		}
		else{
			double p = i;
			p /= (i+j);
			return dp[i][j][1] = p + zeno(i,j-1,0)*(1-p);
		}
	}
	else{
		if(j==0){
			return dp[i][j][f]=0;
		}
		else{
			//i,j-1 
			double p = j;
			p /= (i+j);
			double p2 = (j-1);
			p2 /= (i+j-1);
			if(j==1){
				return dp[i][j][f] = p*zeno(i-1,0,1);
			}
			else{
				return dp[i][j][f] = p*p2*zeno(i,j-2,1)+p*(1-p2)*zeno(i-1,j-1,1);
			}
		}
	}
}


int solve(){
 	int w,b;cin>>w>>b;
 	cout<<fixed<<setprecision(10)<<zeno(w,b,1)<<endl;
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