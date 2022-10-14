//https://codeforces.com/contest/151/problem/B
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
//0->taxi,1->pizza,2->girl
int wnum(string s){
    int f=0;
    int n=s.length();
    string t="";
    lop(i,n,1){
        if(s[i]!='-') t+=s[i];
    }
    string t2(t);
    sort(all(t2),greater<char>());
    n=t2.length();
    if(t2==t){
        if(t2[n-1]==t2[0]) return 0;
        else {
            lop(i,n-1,1){
                if(t2[i+1]==t2[i])return 2;
            }
            return 1;
        }
    }
    return 2;
}
int solve(){
   int n;
   cin>>n;
   string names[n];
   int num[n][3]={0};
   lop(i,n,1){
       int tn;string name;
       cin>>tn>>name;
       names[i]=name;
       lop(j,tn,1){
           string s;cin>>s;
           num[i][wnum(s)]++;
       }
   }
  // lop(i,n,1){cout<<num[i][0]<<" "<<num[i][1]<<" "<<num[i][2]<<endl;}
   vector<string> sets[3];
   lop(j,3,1){
   int ma=0;
   lop(i,n,1)ma=max(ma,num[i][j]);
   lop(i,n,1){
       if(num[i][j]==ma)sets[j].pb(names[i]);
   }}
   cout<<"If you want to call a taxi, you should call: ";
   auto itr=sets[0].end();
   advance(itr,-1);
   for(auto i:sets[0]){
       if(i!=*itr)cout<<i<<", ";
       else cout<<i<<"."<<endl;
   }
    cout<< "If you want to order a pizza, you should call: ";
    itr=sets[1].end();
       advance(itr,-1);

   for(auto i:sets[1]){
       if(i!=*itr)cout<<i<<", ";
       else cout<<i<<"."<<endl;
   }
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    itr=sets[2].end();
       advance(itr,-1);

   for(auto i:sets[2]){
       if(i!=*itr)cout<<i<<", ";
       else cout<<i<<"."<<endl;
   }
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