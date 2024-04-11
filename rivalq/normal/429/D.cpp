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
int Closest_Pair(vector<pii>&v){
	int n=sz(v);
	sort(all(v));
	set<pii>s;
	int best_so_far=1e18;
	int j=0;
	for(int i=0;i<n;i++){
		int d=ceil(sqrt(best_so_far))+5;
		while(j<n && v[i].x-v[j].x>=d){
			s.erase({v[j].y,v[j].x});
			j++;
		}
		auto itr1=s.lower_bound({v[i].y-best_so_far,v[i].x});
		auto itr2=s.upper_bound({v[i].y+best_so_far,v[i].x});
		for(itr1;itr1!=itr2;itr1++){
			int dx=(v[i].x-itr1->y)*(v[i].x-itr1->y);
			int dy=(v[i].y-itr1->x)*(v[i].y-itr1->x);
			mins(best_so_far,dx+dy);
		}
		s.insert({v[i].y,v[i].x});
	}
	return best_so_far;
}
int solve(){
 int n;cin>>n;
 vector<int>a(n+1);
 rep(i,1,n+1)cin>>a[i];
 vector<pii>v;
 int s=0;
 rep(i,1,n+1){
 	s+=a[i];
 	v.eb(s,i);
 }
 cout<<Closest_Pair(v)<<endl;
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