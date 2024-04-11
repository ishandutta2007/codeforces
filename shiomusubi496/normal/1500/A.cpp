/*#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,A[1<<20];
signed main(){
  cin>>N;
  map<int,vector<int>>idx;
  for(int i=0;i<N;i++)cin>>A[i],idx[A[i]].push_back(i);
  for(auto[a,b]:idx)if(b.size()>=4){
    puts("YES");
    cout<<b[0]+1<<' '<<b[1]+1<<' '<<b[2]+2<<' '<<b[3]+2<<endl;
    return 0;
  }
  map<int,vector<pair<int,int>>>mp;
  for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
    int a=abs(A[i]-A[j]);
    auto&V=mp[a];
    for(auto[x,y]:V){
      if(x!=i&&y!=i&&x!=j&&y!=j){
        puts("YES");
        cout<<x+1<<' '<<(A[i]>A[j]?j:i)+1<<' '<<(A[i]>A[j]?i:j)+1<<' '<<y+1<<endl;
        return 0;
      }
    }
    V.push_back({A[i]>A[j]?i:j,A[i]>A[j]?j:i});
  }
  puts("NO");
}*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,A[1<<20];
signed main(){
  cin>>N;
  map<int,vector<int>>idx;
  for(int i=0;i<N;i++)cin>>A[i],idx[A[i]].push_back(i);
  for(auto[a,b]:idx)if(b.size()>=4){
    puts("YES");
    cout<<b[0]+1<<' '<<b[1]+1<<' '<<b[2]+1<<' '<<b[3]+1<<endl;
    return 0;
  }
  map<int,vector<pair<int,int>>>mp;
  for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
    int a=abs(A[i]-A[j]);
    auto&V=mp[a];
    for(auto[x,y]:V){
      if(x!=i&&y!=i&&x!=j&&y!=j){
        puts("YES");
        cout<<x+1<<' '<<(A[i]>A[j]?j:i)+1<<' '<<(A[i]>A[j]?i:j)+1<<' '<<y+1<<endl;
        return 0;
      }
    }
    V.push_back({A[i]>A[j]?i:j,A[i]>A[j]?j:i});
  }
  puts("NO");
}