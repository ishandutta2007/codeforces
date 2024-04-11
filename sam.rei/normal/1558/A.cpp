#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int A,B;
  cin>>A>>B;
  // if K breaks is possible
  // then K = c+d
  // score is A = (N+1)/2+c-d, B=N/2+d-c
  // first serve is unknown
  // can either be any value or any odd value 
  // value is at least the difference 
  if(A<B) swap(A,B);
  int m = (A+B+1)/2;
  vector<int> valid;
  if((A+B)%2==0){
    // max value of c+d given c-d = x c<=Ma, d<=ma
    
    // c+d <= 2c - (c-d)
    // c+d = j
    int c = A-m;
    for(int d=0;c+d<=A+B&&c<=(A+B)/2 &&d<=(A+B)/2;++c,++d){
      valid.push_back(c+d);
    }
  }else{
    int c = A-m;
    int d=0;
    for(;c+d<=A+B&&c<=m-1 &&d<=m;++c,++d){
      valid.push_back(c+d);
    }
    c = A-(m-1);
    d = 0;
    //cout<<c<<" "<<d;
    // if(c<0){++c;++d;}
    for(;c+d<=A+B&&c<=m &&d<=m-1;++c,++d){
      //cout<<c<<" "<<d<<'\n';
      valid.push_back(c+d);
    }
    sort(RANGE(valid));
  }
  cout<<valid.size()<<'\n';
  for(int i=0;i<valid.size();++i) cout<<valid[i]<<" \n"[i==valid.size()-1];
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