#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

int main(){
  std::ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n,k;//TC;
  cin>>n>>k;
  if(n%2==1 && k%2==0){
    cout<<"-1"<<endl;
    return 0;
  }
  // check if n == k
  int r = (n+k-1)/k;
  int res=0;
  int z;
  if(n==r*k){
    for(int j=0;j<r;++j){
      cout<<"?";
      for(int i=1;i<=k;++i){
	cout<<" "<< i+k*j;
      }
      cout<<endl;
      cin>>z;
      res=res^z;
    }
  }else{
    if((r*k-n)%2!=0)++r;
    // r is least number such that rk == n mod 2
    vector<int> appearances(n,1);
    //  
    while(r*k> n*((r-1)|1)){
      r+=1;
      if((r*k-n)%2!=0)++r;
    }
    int excess = r*k-n;
    //cerr<<r<<endl;
    for(int i=0;i<n;++i){
      int change = min(excess,2*((r-1)/2));
      appearances[i]+=change;
      excess -=change;
      //cerr<<appearances[i]<<" ";
    }
    //cerr<<endl;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
      q.emplace(appearances[i],i);
    }
    for(int i=0;i<r;++i){
      // take k from the stack
      cout<<"?";
      vector<int> taken(k);
      for(int j=0;j<k;++j){
	taken[j] = q.top().second;
	//cerr<<q.top().first<<" "<<q.top().second<<endl;
	q.pop();	
      }
      for(int x : taken){
	cout<<" "<<(x+1);
	--appearances[x];

	q.emplace(appearances[x],x);
      }
      cout<<endl;
      cin>>z;
      res^=z;
    }
    
  }
  cout<<"! "<<res<<endl;
}