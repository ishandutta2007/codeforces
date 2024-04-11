//https://codeforces.com/contest/1278/problem/C
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
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
#define mod 1000000007
using namespace std;
int solve(){
  int n;cin>>n;
 vector<int> left,right;
 int red=0,blue=0;
 lop(i,n,1){
     int t;cin>>t;
     left.pb(t);
     if(t==1)red++;
     else blue++;
 }
 lop(i,n,1){
     int t;cin>>t;
     right.pb(t);
     if(t==1)red++;
     else blue++;
 }
 reverse(all(left));
 int toeat=1;
 if(blue>red)toeat=2;
 //if(blue==red){cout<<0<<endl;ret;}
 int diff=abs(red-blue);
 int ja=mod;
 map<int,int> lsc,rsc;
 lsc[0]=0,rsc[0]=0;
 int c=0,r=0;
 lop(i,n,1){
     if(left[i]==toeat)
     c++;
     else c--;
     if(lsc.count(c)==0)
     lsc[c]=i+1;
     else lsc[c]=min(lsc[c],i+1);
     if(right[i]==toeat)r++;
     else r--;
     if(rsc.count(r)==0)
     rsc[r]=i+1;
     else rsc[r]=min(i+1,rsc[r]);
 }
 if(rsc.count(diff))ja=rsc[diff];
 
 for(int i=0;i<n;i++){
       if(left[i]==toeat)diff--;
       else diff++;
       if(rsc.count(diff))ja=min(ja,i+1+rsc[diff]);
 }
cout<<ja<<endl;

}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}