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


int solve(){
 	int n;cin>>n;
 	vector<pair<int,char>>vec(n+1);
 	vector<int>temp;
 	vector<vector<int>>pb;
 	vector<vector<int>>pr;
 	int cntb=0,cntr=0;
 	vector<int>tb,tr;
 	rep(i,1,n+1){
 		cin>>vec[i];
 		if(vec[i].y=='B')tb.pb(vec[i].x);
 		else if(vec[i].y=='R')tr.pb(vec[i].x);
 		else{
 			pb.push_back(tb);
 			pr.push_back(tr);
 			tb.clear();tr.clear();
 			temp.pb(vec[i].x);
 		}
 	}
 	if(sz(temp)==0){
 		int val=0;
 		if(!tb.empty())val+=tb.back()-tb.front();
 		if(!tr.empty())val+=tr.back()-tr.front();
 		cout<<val<<endl;return 0;
 	}
 	int ans=0;
 	for(int i=0;i<sz(temp)-1;i++){
 		int l=temp[i];
 		int r=temp[i+1];
 		if(sz(pb[i+1])>0 && sz(pr[i+1])>0){
 			int val=3*(r-l);
 			int mx=0;
 			if(sz(pr[i+1])==1){
 				val-=max(pr[i+1][0]-l,r-pr[i+1][0]);
 			}
 			else{	mx=0;maxs(mx,pr[i+1][0]-l);
 				maxs(mx,r-pr[i+1].back());
 				for(int j=0;j<sz(pr[i+1])-1;j++){
 					maxs(mx,pr[i+1][j+1]-pr[i+1][j]);
 				}
 				val-=mx;mx=0;	
 			}
 			if(sz(pb[i+1])==1){
 				val-=max(pb[i+1][0]-l,r-pb[i+1][0]);
 			}
 			else{
 				mx=0;maxs(mx,pb[i+1][0]-l);
 				maxs(mx,r-pb[i+1].back());
 				for(int j=0;j<sz(pb[i+1])-1;j++){
 					maxs(mx,pb[i+1][j+1]-pb[i+1][j]);
 				}
 				val-=mx;mx=0;	
 			}
 			ans+=min(val,2*(r-l)); 			
 		}
 		else{
 			ans+=(r-l);
 			if(sz(pr[i+1])==0 && sz(pb[i+1])==0)continue;
 			ans+=r-l;
 			if(sz(pr[i+1])==0)swap(pr[i+1],pb[i+1]);
 			int mx=0;
 			if(sz(pr[i+1])==1){
 				ans-=max(pr[i+1][0]-l,r-pr[i+1][0]);
 			}
 			else{	mx=0;maxs(mx,pr[i+1][0]-l);
 				maxs(mx,r-pr[i+1].back());
 				for(int j=0;j<sz(pr[i+1])-1;j++){
 					maxs(mx,pr[i+1][j+1]-pr[i+1][j]);
 				}
 				ans-=mx;mx=0;	
 			}
 		}
 	}
 	if(pr[0].size()>0)ans+=temp[0]-pr[0].front();
 	if(pb[0].size()>0)ans+=temp[0]-pb[0].front();
 	if(tr.size()>0)ans+=tr.back()-temp.back();
 	if(tb.size()>0)ans+=tb.back()-temp.back();
 	cout<<ans<<endl;
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