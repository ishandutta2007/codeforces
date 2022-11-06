#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
void one(){
  int N;
  cin>>N;
  vi vals(N);
  for(int i=0;i<N;++i)cin>>vals[i];
  for(int j=0;j<2;++j){
    int front =0;
    int back = N-1;
    bool works = true;
    int skip = -1;
    while(front<back){
      if(vals[front]==skip){++front;}
      else if(vals[back]==skip){--back;}
      else {
        if(vals[front]!=vals[back]){
          if(skip==-1){
            skip=vals[front];
            ++front;
          }else{
            works = false;
            break;
          }
        }else{
          ++front;
          --back;
        }
      }
    }
    if(works){
      cout<<"YES\n";
      return;
    }
    reverse(RANGE(vals));
  }
  cout<<"NO\n";
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