#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e15;
signed main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<int>a(n),l(n,-INF),r(n,-INF);
    for(int&i:a)cin>>i;
    l[0]=0;
    for(int i=1;i<n;i++){
      if(l[i-1]!=-INF&&a[i-1]>=l[i-1])l[i]=a[i-1]-l[i-1];
    }
    r[n-1]=0;
    for(int i=n-2;i>=0;i--){
      if(r[i+1]!=-INF&&a[i+1]>=r[i+1])r[i]=a[i+1]-r[i+1];
    }
    for(int i=0;i<n;i++)if(a[i]-l[i]-r[i]==0){
      puts("YES");
      goto home;
    }
    for(int i=0;i<n-1;i++)if(a[i]-r[i+1]==a[i+1]-l[i]&&a[i]-r[i+1]>=0&&r[i+1]!=-INF){
      puts("YES");
      goto home;
    }
    puts("NO");
    home:;
  }
}