//https://codeforces.com/problemset/problem/283/A
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int i=0;i<n;i++)
#define inarr(arr,n) rep1(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(a,x) for(auto x:a)
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define gcd(a,b) __gcd(a,b)
#define pres(a,x) a.find(x)!=a.end()
#define sz(a) (int)a.size()
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<ll,ll>
#define vec vector<int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
#define narak 998244353
const int inf1=1e9;
const ll inf2=1e18;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n;cin>>n;
  vector<ll> v;
  v.pb(0);
  ll arr[200000]={0};
  ll sum=0;
  rep3(n){
    int t;cin>>t;
    if(t==1){
        ll a,x;cin>>a>>x;
        sum=sum+a*x;
        ll n=v.size();
        //for(int i=0;i<min(a,n);i++)v[i]+=x;
        double k=(double)sum/n;
        arr[a-1]+=x;
        cout<<fixed<<setprecision(6)<<k<<endl;
    }
    else if(t==2){
        int k;cin>>k;sum+=k;
        v.pb(k);
        double n=v.size();
        cout<<fixed<<setprecision(6)<<sum/n<<endl;
    }
    else if(v.size()>1 && t==3){

        int n=v.size();
        sum-=v[n-1];
        sum-=arr[n-1];
        arr[n-2]+=arr[n-1];
        arr[n-1]=0;
        n--;v.pop_back();
        double k=(double)sum/n;
        cout<<fixed<<setprecision(6)<<k<<endl;
    }
    //cout<<v.size()<<endl;
  }
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}