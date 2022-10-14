//https://codeforces.com/contest/225/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int bs(vector<ll> kb,int n,int s){
    int l=0,u=n-1;
    int mid,i=0;
    while(l<=u){
        mid=(l+u)/2;
        if(kb[mid]==s)return mid;
        else if(kb[mid]>s){
            u=mid-1;
        }
        else {
            l=mid+1;i=mid;
        }
    }
    return i;
}
int solve(){
  int s,k;cin>>s>>k;
  ll arr[100]={0};
  arr[0]=0;
  arr[1]=1;
  for(int i=2;i<100;i++){
    int j=k;
    int c=i-1;
    while(j-- && j>=0 && c>=0) {
     arr[i]+=arr[c],c--;
     if(arr[i]>s){arr[i]=0;break;}
     }
     if(arr[i]==0)break;
  }
 vector<ll> kb;
 for(int i=0;i<100;i++){
     if(arr[i])
     kb.pb(arr[i]);
 }
 set<ll> an;
 kb.pb(0);
 sort(all(kb));
 int n=kb.size();
 while(s>0){
   if(s>kb[n-1]) {
       s-=kb[n-1];
       an.insert(kb[n-1]);
       n--;
   }
   else{
   int i=bs(kb,n,s);
   auto itr=kb.begin();
   advance(itr,i);
   s-=kb[i];
   an.insert(kb[i]);
   kb.erase(itr);n--;
   }
 }
 if(an.size()==1){
     cout<<2<<endl<<0<<" ";
 }
 else cout<<an.size()<<endl;
 for(auto i:an)cout<<i<<" ";
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}