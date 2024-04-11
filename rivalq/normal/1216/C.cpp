//https://codeforces.com/contest/1216/problem/C
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
int ch(int a,int b,int c,int d){
    if(a>d||b<c)return 0;
    else return 1;
}
int li(int x1,int x2,int l,int r){
    if(x1>=l && x1<=r && x2>=l && x2<=r)return 1;
    ret;
}
int solve(){
 int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
 int cnt=0;
 pii p[4]={{-1,-1}};
 int l1,r1,l2,r2;
 cin>>l1>>r1>>l2>>r2;
 if(l1<=x1 && x1<=l2)p[0]={r1,r2};
 if(r1<=y1 && y1<=r2)p[1]={l1,l2};
 if(l1<=x2 && x2<=l2)p[2]={r1,r2};
 if(r1<=y2 && y2<=r2)p[3]={l1,l2};
 int a,b,c,d;cin>>a>>b>>c>>d;  
 if(a<=x1 && c>=x1 && ch(a,c,l1,l2)){
     if(p[0].fr==-1)p[0].fr=b;
     else p[0].fr=min(r1,b);
     if(p[0].sc==-1)p[0].sc=d;
     else p[0].sc=max(r2,d);
 }
 if(!ch(a,c,l1,l2)){
     if((y1>=b && y2<=d &&li(x1,x2,a,c)) || (y1>=r1 && y2<=r2 && li(x1,x2,l1,l2))){
         cout<<"NO"<<endl;
         ret;
     }
     else{
         cout<<"YES"<<endl;
         ret;
     }
 }
 if(!ch(b,d,r1,r2)){
     if((x1>=a && x2<=c && li(y1,y2,b,d)) || (x1>=l1 && x2<=l2 && li(y1,y2,r1,r2))){
         cout<<"NO"<<endl;
         ret;
     }
     else{
         cout<<"YES"<<endl;
         ret;
     }
 }
 if(b<=y1 && d>=y1 && ch(b,d,r1,r2)){
     if(p[1].fr==-1)p[1].fr=a;
     else p[1].fr=min(l1,a);
     if(p[1].sc==-1)p[1].sc=c;
     else p[1].sc=max(l2,c);
 }
 if(a<=x2 && c>=x2 && ch(a,c,l1,l2)){
     if(p[2].fr==-1)p[2].fr=b;
     else p[2].fr=min(r1,b);
     if(p[2].sc==-1)p[2].sc=d;
     else p[2].sc=max(r2,d);
 }
 if(b<=y2 && d>=y2 && ch(b,d,r1,r2)){
     if(p[3].fr==-1)p[3].fr=a;
     else p[3].fr=min(l1,a);
     if(p[3].sc==-1)p[3].sc=c;
     else p[3].sc=max(l2,c);
 }
 for(int i=0;i<=3;i++){
     //cout<<p[i].fr<<" "<<p[i].sc<<endl;
    if(p[i].fr==-1 && p[i].sc==-1)continue; 
    if(i%2==0){
        if(y1>=p[i].fr && y2<=p[i].sc)cnt++;
    }
    else{
         if(x1>=p[i].fr && x2<=p[i].sc)cnt++;
    }
 }
 if(cnt==4){
     cout<<"NO"<<endl;
 }
 else{
     cout<<"YES"<<endl;
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