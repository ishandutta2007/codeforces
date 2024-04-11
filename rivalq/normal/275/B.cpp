//https://codeforces.com/contest/275/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define fr first
#define sc second
#define eb emplace_back
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int c_check(vector<string> board,int x1,int y,int x2){
    for(int i=min(x1,x2);i<=max(x1,x2);i++){
        if(board[i][y]=='W')return 0;
    }
    return 1;
}
int r_check(vector<string> board,int x,int y1,int y2){
     for(int j=min(y1,y2);j<=max(y2,y1);j++){
        if(board[x][j]=='W')return 0;
    }
    return 1;
}
int solve(){
  int n,m;cin>>n>>m;
  vector<string> board;
  board.resize(n);
  lop(i,n,1){
      cin>>board[i];
  }
   int row[n][m],column[n][m];
  vector<pii> v;
  lop(i,n,1){
      lop(j,m,1){
          if(board[i][j]=='B') v.pb({i,j});
          row[i][j]=column[i][j]=0;
      }
  }
 
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(j==0)continue;
          if(board[i][j-1]=='B')row[i][j]=row[i][j-1]+1;
      }
  } 
  for(int j=0;j<m;j++){
      for(int i=0;i<n;i++){
          if(i==0)continue;
          if(board[i-1][j]=='B')column[i][j]=column[i-1][j]+1;
      }
  } 
  int s=v.size();
  sort(all(v),greater<pii>());
  //for(auto i:v)cout<<i.fr<<" "<<i.sc<<endl;
  for(int i=0;i<s;i++){
      int x1=v[i].fr,y1=v[i].sc;
      for(int j=i+1;j<s;j++){
      int x2=v[j].fr,y2=v[j].sc;
      int q=1;
      if(column[x1][y2]>=x1-x2 && row[x1][max(y1,y2)]>=abs(y1-y2) && board[x1][y2]=='B')q=0;
      if(column[x1][y1]>=x1-x2 && row[x2][max(y1,y2)]>=(y1-y2) && board[x2][y1]=='B')q=0;
      if(q){cout<<"NO\n";ret;}
    }
  }
  cout<<"YES"<<endl;ret;
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