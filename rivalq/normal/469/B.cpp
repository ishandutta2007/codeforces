//https://codeforces.com/problemset/problem/469/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define end return 0
using namespace std;
int ch(int x1,int y1,int x2,int y2){
    if((x2<=x1 && x1<=y2)|| (x2<=y1 && y1<=y2)) return 1;
    else if((x1<=x2 && x2<=y1)|| (x1<=y2 && y2<=y1)) return 1;
    return 0;
}
int solve(){
  int p,q,l,r;
  cin>>p>>q>>l>>r;
  int a1[p][2],a2[q][2];
  int visit[r+1]={0};
  lop(i,p,1){cin>>a1[i][0]>>a1[i][1];}
  lop(i,q,1){cin>>a2[i][0]>>a2[i][1];}
  int h=0;
  lop(i,q,1){
      lop(j,p,1){
          rep(k,r+1,l){
              if(ch(a2[i][0]+k,a2[i][1]+k,a1[j][0],a1[j][1])){visit[k]=1;h++;}
          }
         
      }
  }
  int c=0;
  rep(i,r+1,l){
      if(visit[i]) c++;
  }
  cout<<c<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    end;
}