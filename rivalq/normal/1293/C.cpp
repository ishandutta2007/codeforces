//https://codeforces.com/contest/1293/problem/0
#include<bits/stdc++.h>
#define rep1(i,n,a)    for(int i=0;i<n;i+=a)
#define rep2(i,n,a)    for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep1(i,n,1)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define trav(a,x)      for(auto x:a)
#define endl           "\n"
#define eb             emplace_back
#define fr             first
#define sc             second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)         (int)a.size()
#define pii            pair<int,int>
#define psi            pair<string,int>
#define pss            pair<string,string>
#define pll            pair<ll,ll>
#define vec            vector<int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int SEG[1000000]={0};
void buildseg(int arr[],int start,int end,int node){
    if(start==end){
        SEG[node]=arr[start];
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildseg(arr,start,mid,2*node);
        buildseg(arr,mid+1,end,2*node+1);
        SEG[node]=max(SEG[2*node],SEG[2*node+1]);
    }
}
void update(int arr[],int idx,int start,int end,int node,int nval){
   if(start==end){
       arr[idx]=nval;
       SEG[node]=nval;
       return;
   }
   else{
       int mid=(start+end)/2;
       if(idx<=mid){
           update(arr,idx,start,mid,2*node,nval);
       }
       else{
           update(arr,idx,mid+1,end,2*node+1,nval);
       }
       SEG[node]=max(SEG[2*node],SEG[2*node+1]);
   }
   
}
int getans(int l,int r,int start,int end,int node){
   if(r<start || end<l){
       return 0;
   }
   else if(r>=end && start>=l){
       return SEG[node];
   }
   else{
     int mid=(start+end)/2;  
     int p1=getans(l,r,start,mid,2*node);
     int p2=getans(l,r,mid+1,end,2*node+1);
     return max(p1,p2);
   }


}
int solve(){
  int n,q;cin>>n>>q;
  int arr1[n+1]={0};
  int arr2[n+1]={0};
  int bl=0;
  rep3(q){
    int a;int b;cin>>a>>b;
    if(a==1){
       if(arr1[b]){
           arr1[b]=0;
           if(arr2[b])bl--;
           if(b>1 && arr2[b-1])bl--;
           if(b<n && arr2[b+1])bl--;
       }
       else{
           arr1[b]=1;
           if(arr2[b])bl++;
           if(b>1 && arr2[b-1])bl++;
           if(b<n && arr2[b+1])bl++;
       }
    }
    else{
         if(arr2[b]){
           arr2[b]=0;
           if(arr1[b])bl--;
           if(b>1 && arr1[b-1])bl--;
           if(b<n && arr1[b+1])bl--;
       }
       else{
           arr2[b]=1;
           if(arr1[b])bl++;
           if(b>1 && arr1[b-1])bl++;
           if(b<n && arr1[b+1])bl++;
       }
    }
    //cout<<bl<<endl;
    if(bl==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
     
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