#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i){
    cin>>a[i];
    --a[i];
  }
  vector<bool> taken(n,false);
  vector<int> assign(n,-1);
  vector<int> takers(n,-1);
  int res = 0;
  for(int i=0;i<n;++i){
    if(!taken[a[i]]){
      taken[a[i]]=true;
      assign[i] = a[i];
      takers[a[i]]= i;
      ++res;
    }
  }
  int leastnot = 0;
  vector<int> neithered;
  
  for(int j=0;j<n;++j){
    if(assign[j]==-1 && taken[j] == false)neithered.push_back(j);
  }
  if(neithered.size()==1){
    // try to assign this to a[i], rest to a[j];
    int w = neithered[0];
    int z = takers[a[w]];
    assign[z] = w;
    taken[w] = true;
    takers[a[w]]=w;
    takers[w] = z;
    assign[w] = a[w];
  }
  else{
    int ns = neithered.size();
    for(int i=0;i<ns;++i){
      assign[neithered[i]]=neithered[(i+1)%ns];
      taken[neithered[i]]=true;
    }
  }
  for(int j=0;j<n;++j){
    if(assign[j] != -1)continue;
    while(taken[leastnot])++leastnot;
    assign[j]= leastnot;
    taken[leastnot] = true;
  }

  cout<<res<<'\n'<<(assign[0]+1);
  for(int i=1;i<n;++i){
    cout<<' '<<(assign[i]+1);
  }
  cout<<'\n';
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}