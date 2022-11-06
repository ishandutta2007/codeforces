#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
template< class T>
vector<T> readvec(int N){
  vector<T> res(N);
  for(int i=0;i<N;++i)cin>>res[i];
  return res;
}
void one(){
  int N,K;
  cin>>N>>K;
  vector<int> t = readvec<int>(N);
  // let j be the greatest set bit of ||a xor b||
  // wlog a > b
  // must make that bit greedy, larger bits of x do not matter
  vector<int> mins(1<<K,1<<K);
  vector<vector<bool>> exists(K+1);
  for(int i=0;i<=K;++i){
    exists[i].resize(1<<i,false);
  }
  for(int j : t)exists[K][j] = true;
  for(int k= K-1;k>=0;--k){
    for(int j=0;j<(1<<k);++j){
      exists[k][j] = exists[k+1][j*2] | exists[k+1][j*2+1];
    }
  }
  for(int k=0;k<K;++k){
    for(int i=0;i<(1<<(K-k-1));++i){
      int val = 1<<K;
      // j is the first k+1 bits
      for(int j=0;j< (1<<(k+1));j+=2){
        if(exists[k+1][j] && exists[k+1][j+1]){
          // we have the ability to make 2^k be the biggest difference bit
          int d = 1;
          int l = j;
          int r = j+1;
          for(int cb = k+1;cb<K;++cb){
            int currb = ((i>>(K-cb-1))&1);
            d*=2;
            l*=2;
            r*=2;
            if(exists[cb+1][l^1^currb] && exists[cb+1][r^currb]){
              r^=currb;
              l^=currb^1;
              d-=1;
            }
            else if(exists[cb+1][l] && exists[cb+1][r]){
              // do nothing
            }else if(exists[cb+1][l^1] && exists[cb+1][r^1]){
              l^=1;
              r^=1;
            }else{
              r^=currb^1;
              l^=currb;
              d+=1;
            }
          }
          assert( d == (r^i)-(l^i));
          //cout<<k<<" "<<i<<" "<<d<<" "<<l<<" "<<r<<endl;
          val = min(val,d);
        }
      }
      for(int j=0;j< (1<<k);++j){
        mins[(j<<(K-k))+i] = min(mins[(j<<(K-k))+i],val);
        mins[(j<<(K-k))+(1<<(K-k))-1-i] = min(mins[(j<<(K-k))+(1<<(K-k))-1-i],val);
      }
    }
  }
  for(int i=0;i<(1<<K);++i){
    cout << mins[i] << " \n"[i+1==(1<<K)];
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  one();
  cout<<flush;
}