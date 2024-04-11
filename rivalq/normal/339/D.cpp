//https://codeforces.com/problemset/problem/339/D
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
const int N=150000;
int level[2*N]={0};
void buildseg(ll SEG[],ll arr[],int start,int end,int node){
    if(start==end){
        SEG[node]=arr[start];
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildseg(SEG,arr,start,mid,2*node);
        buildseg(SEG,arr,mid+1,end,2*node+1);
        level[node]=level[2*node]+1;
        if(level[node]%2)
        SEG[node]=(SEG[2*node]|SEG[2*node+1]);
        else
        SEG[node]=(SEG[2*node]^SEG[2*node+1]);

    }
}
void update(ll SEG[],ll arr[],int idx,int start,int end,int node,int nval){
   if(start==end && start==idx){
       arr[idx]=nval;
       SEG[node]=nval;
       return;
   }
   if(idx<start || idx>end)return;
   else{
       int mid=(start+end)/2;
       if(idx<=mid){
           update(SEG,arr,idx,start,mid,2*node,nval);
       }
       else{
           update(SEG,arr,idx,mid+1,end,2*node+1,nval);
       }
       if(level[node]%2)
        SEG[node]=(SEG[2*node]|SEG[2*node+1]);
        else
        SEG[node]=(SEG[2*node]^SEG[2*node+1]);

   }
   
}
/****int getans(int SEG[],int l,int r,int start,int end,int node){
   if(r<start || end<l){
       return hell;
   }
   else if(r>=end && start>=l){
       return SEG[node];
   }
   else{
     int mid=(start+end)/2;  
     int p1=getans(SEG,l,r,start,mid,2*node);
     int p2=getans(SEG,l,r,mid+1,end,2*node+1);
     return min(p1,p2);
   }


}*****/
 ll arr[N]={0};
 ll SEG[2*N]={0};
int solve(){
  int n,m;cin>>n>>m;
  ll k=1L<<n;
  inarr(arr,k);
  buildseg(SEG,arr,0,k-1,1);
  lop(i,m,1){
      int p,b;cin>>p>>b;
      update(SEG,arr,p-1,0,k-1,1,b);
      cout<<SEG[1]<<endl;
  }

  ret;
}
int main(){
    IOS;
    //freopen("output1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}