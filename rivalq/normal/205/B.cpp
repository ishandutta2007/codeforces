//https://codeforces.com/contest/205/problem/B
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
int solve(){
  int n;
  cin>>n;
  ll arr[n];
  lop(i,n,1) cin>>arr[i];
  
 ll c=0;
for(int i=0;i<n-1;){
    if(arr[i+1]<arr[i]){
        int j=i+1;
        ll mi=arr[j];
        while(arr[j+1]<arr[j] && j+1<n){
            mi=arr[j+1];
            j++;
        }
        
        c+=arr[i]-mi;
        j=i+1;
        while(arr[j+1]<arr[j] && j+1<n){
            arr[j]=arr[i];
            j++;
        }
        i=j;

    }
    else i++;
}
 cout<<c<<endl;
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