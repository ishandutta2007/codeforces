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


const int N=1e6+5;

int a[N];
int p[N];
pii rnk[N];

int root(int x){
	if(p[x]==x)return x;
	return p[x]=root(p[x]);
}


int solve(){
 	int n;cin>>n;
 	vector<int>v(n+1),r(n+1);
 	rep(i,1,n+1){
 		char c;cin>>c;
 		if(c=='?')v[i]=-1;
 		else v[i]=c-48;
 	}
 	int j1=n+1;
 	int j2=n+1;
 	for(int i=n;i>0;i--){
 		if(v[i]==0){
 			j1=i;
 		}
 		else if(v[i]==1){
 			j2=i;
 		}
 		a[i]=max(j1,j2)-i;
 		rnk[i]={a[i],i};
 	}
 	sort(rnk+1,rnk+1+n);
 	for(int i=1;i<=n+1;i++)p[i]=i;
 	int j=1; 
 	for(int i=1;i<=n;i++){
 		while(j<=n && rnk[j].x<i){
 			p[rnk[j].y]=rnk[j].y+1;
 			j++;
 		}
 		int cnt=0;
 		int l=1;
 		while(1){
 			int j=root(l);
 			if(j>n)break;
 			cnt++;
 			l=j+i;
 		}
 		cout<<cnt<<" ";
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