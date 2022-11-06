#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int N;
  cin>>N;
  vector<int> A(N);
  int xo=0;
  for(int i=0;i<N;++i){
    cin>>A[i];
    xo^=A[i];
  }
  if(xo!=0){
    cout<<"NO\n";
    return;
  }
  if(N%2 == 1){
    // 1 3 5 7 9 11 ... puts 0 at the end
    // 9 7 5 3 1
    cout<<"YES\n"<<N-2<<"\n";
    vector<int> res;
    for(int i=1;i<N;i+=2){
      res.push_back(i);
    }
    for(int j=N-4;j>=1;j-=2){
      res.push_back(j);
    }
    for(int i=0;i<res.size();++i){
      cout<<res[i]<<" \n"[i==res.size()-1];
    }
    return;
  }
  else{
    if(A[0]==0){
      --N;
      cout<<"YES\n"<<N-2<<"\n";
      vector<int> res;
      for(int i=1;i<N;i+=2){
        res.push_back(i);
      }
      for(int j=N-4;j>=1;j-=2){
        res.push_back(j);
      }
      for(int i=0;i<res.size();++i){
        cout<<(res[i]+1)<<" \n"[i==res.size()-1];
      }
      return;
    }
    if(A[N-1]==0){
      --N;
      cout<<"YES\n"<<N-2<<"\n";
      vector<int> res;
      for(int i=1;i<N;i+=2){
        res.push_back(i);
      }
      for(int j=N-4;j>=1;j-=2){
        res.push_back(j);
      }
      for(int i=0;i<res.size();++i){
        cout<<res[i]<<" \n"[i==res.size()-1];
      }
      return;
    }
    // if either are 0, we are okay
    // odd lenght gap between 1s can be elimed
    // is there a point that you can turn into two odd-lengthed sequences where you can do it
    int par = 0;
    for(int spl=0;spl<N;++spl){
      par ^= A[spl];
      if(spl%2==0 && par ==0){
        // can split here
        vector<int> res;
        for(int i=1;i<spl+1;i+=2){
          res.push_back(i);
        }
        for(int j=spl-3;j>=1;j-=2){
          res.push_back(j);
        }
        for(int i=1;i<N-1-spl;i+=2){
          res.push_back(spl+1+i);
        }
        for(int j=N-spl-5;j>=1;j-=2){
          res.push_back(spl+1+j);
        }
        
        cout<<"YES\n"<<res.size()<<"\n";
        for(int i=0;i<res.size();++i){
          cout<<res[i]<<" \n"[i==res.size()-1];
        }
        return;
      }
    }
    cout<<"NO\n";
  }
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