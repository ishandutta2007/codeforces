#include<bits/stdc++.h>
#define int long long
using namespace std;
using P=pair<int,int>;
signed main(){
  int n; cin>>n;
  vector<P> item(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>item[i].first>>item[i].second;
    sum+=item[i].first;
  }
  int ok=0,ng=sum+1;
  sort(item.begin(),item.end(),[](P a,P b){return a.second<b.second;});
  while(ng-ok>1){
    int mid=(ok+ng)/2;
    int a=sum-mid,b=mid;
    bool bo=true;
    for(int i=0;i<n;i++){
      if(b){
        if(a<item[i].second)bo=false;
      }
      a+=item[i].first;
      b=max(b-item[i].first,0ll);
    }
    if(bo)ok=mid;
    else ng=mid;
  }
  cout<<ok+(sum-ok)*2<<endl;
}