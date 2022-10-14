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
#define hell           998244353
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
int expo(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
int get(int num,int len){
	int ans=0;
    vector<int>dig;
    while(num){
    	dig.pb(num%10);
    	num/=10;
    } 
    len=sz(dig);
    while(!dig.empty()){
        ans=ans+dig.back()*expo(10,2*len-1,hell);
        ans%=hell;len--;
        dig.pop_back();
    }
    return ans;
}
int get2(int num,int len){
	int ans=0;
    vector<int>dig;
    while(num){
    	dig.pb(num%10);
    	num/=10;
    }
    len=sz(dig)-1; 
    while(!dig.empty()){
        ans=ans+dig.back()*expo(10,2*len,hell);
        ans%=hell;len--;
        dig.pop_back();
    }
    return ans;
}

int solve(){
 int n;cin>>n;
 vector<int>v(n+1);
 vector<int>cnt(11);
 vector<int>b(n+1);
 for(int i=1;i<=n;i++){
 	cin>>v[i];
 	int t=v[i];
 	int c=0;
 	while(t){
 		t/=10;
 		c++;
 	}
 	cnt[c]++;
 	b[i]=c;
 }
 int ans=0;
 for(int i=1;i<=n;i++){
 	for(int j=1;j<=10;j++){
 		if(cnt[j]==0)continue;
        if(b[i]<=j){
        	int len=b[i];
            ans=ans+cnt[j]*get(v[i],len);
            ans=ans+cnt[j]*get2(v[i],len-1);
            ans%=hell; 
        } 
        else{
        	int match=pow(10,j);
            int num=v[i]%match;
            int val=get(num,j);
            val=val+get2(num,j-1);
            val=val+2*(v[i]/match)*expo(10,2*j,hell);
            val=val*cnt[j];
            ans=ans+val;
            ans%=hell; 
        }
 	}
 }
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