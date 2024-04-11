//https://codeforces.com/contest/260/problem/B
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
int iss(string s){
    if(s[2]=='-' && s[5]=='-'){
         for(int i=0;i<10;i++){
             if(i!=2 && i!=5){
                 if(!isdigit(s[i])) return 0;
             }
         }
         string t=s.substr(6,4);
         int y=stoi(t);
         int m=stoi(s.substr(3,2));
         int d=stoi(s.substr(0,2));
         if(y>=2013 && y<=2015 && m>=1 && m<=12 &&d<=31&&d>=1){
            if(m<=7){
                if(m%2==0){
                  if(m==2 && d<=28)return 1;
                  else if(m!=2 && d<=30) return 1;
                  else return 0;
                }
                else return 1;
            }
            else{
                if(m&1){
                    if(d<=30) return 1;
                    else return 0;
                }
                else return 1;
            }
        }
    return 0;
   }
return 0;
}
int solve(){
  string s;cin>>s;
  int n=s.length();
  multimap<string,string> mp;
  for(int i=0;i+9<n;i++){
    string ss=s.substr(i,10);
    if(iss(ss))mp.insert({ss,ss});
  }
  int ma=0;
  string ms;
  for(auto i:mp){
      int t=mp.count(i.first);
      if(t>ma){ma=t,ms=i.first;}
  }
 cout<<ms<<endl;

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