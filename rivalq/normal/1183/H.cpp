//https://codeforces.com/contest/1183/problem/H
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
//const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// Function which returns the numbe of 
// unique subsequences of length K
vector<ll> v1(101, 0); 
vector<ll> v2(101, 0); 
vector<ll> v3(26,0); 
vector<ll> ans(101,0);   
void solution(string &A, int k) { 
    // seiz of the vector 
    // which does is constant 
    const int N = A.length(); 
    ans[0]=1;
    // initiate separately for k = 1 
    // intiate the last element 
    v2[N - 1] = 1; 
    v3[A[N - 1] - 'a'] = 1; 
  
    // initiate all other elements of k = 1 
    for (int i = N - 2; i >= 0; i--) { 
  
        // initialize the front element 
        // to vector v2 
        v2[i] = v2[i + 1]; 
  
        // if element v[a[i]-1] is 0 
        // then increment it in vector v2 
        if (v3[A[i] - 'a'] == 0) { 
            v2[i]++; 
            v3[A[i] - 'a'] = 1; 
        } 
    } 
    ans[1]=v2[0];
    ans[N]=1;
    // iterate for all possible values of K 
    for (int j = 1;j<N-1;j++) { 
  
        // fill the vectors with 0 
        fill(v3.begin(), v3.end(), 0); 
  
        // fill(v1.begin(), v1.end(), 0) 
        // the last must be 0 as from last no unique 
        // subarray can be formed 
        v1[N - 1] = 0; 
  
        // Iterate for all index from which unique 
        // subsequences can be formed 
        for (int i = N - 2; i >= 0; i--) { 
  
            // add the number of subsequence formed 
            // from the next index 
            v1[i] = v1[i + 1]; 
  
            // start with combinations on the 
            // next index 
           if(v1[i]<=inf2)v1[i]=v1[i]+v2[i + 1]; 
            // Remove the elements which have 
            // already been counted 
            v1[i] = v1[i] - v3[A[i] - 'a']; 
  
            // Update the number used 
            v3[A[i] - 'a'] = v2[i + 1]; 
        } 
  
        // prepare the next iteration 
        // by filling v2 in v1 
        ans[j+1]=v1[0];
        v2 = v1; 
    } 
  
} 
int solve(){
 ll n,k;cin>>n>>k;
 if(k==2){
     cout<<1<<endl;ret;
 }
 string s;cin>>s;           
 ll a=0;
 solution(s,n); 
 for(ll i=n;i>=0;i--){
     if(ans[i]<=k){
         a+=ans[i]*(n-i);
         k-=ans[i];
     }
     else{
        a+=k*(n-i);
        k=0;
        break;
     }
 } 
 if(k>0){
     cout<<-1<<endl;ret;
 }
 cout<<a<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}