#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
const string alphabet = "abcdefghijklmnopqrstuvwxyzF";
void one(){
  string s;
  cin>>s;
  int n = s.length();
  vector<int> counts(26,0);
  for(char c: s) ++counts[ (int)(c-'a')];
  // can always achieve 1 or 0 as a goal
  // if 0 is achievable have to be careful
  int nd = 0;
  int lv = 26;
  int nlv =26 ;
  int nnlv = 26;
  bool can0 = false;
  int lz = 26;
  for(int i=0;i<26;++i){
    if(counts[i]>0){
      if(counts[i]==1){
        can0=true;
        if(lz==26)lz=i;
      }
      ++nd;
      if(lv==26){
        lv = i;
      }
      else if(nlv==26){
        nlv = i;
      }else if (nnlv ==26){
        nnlv = i;
      }
    }
  }
  if(can0){
    --counts[lz];
    cout<<alphabet[lz];
    for(int i=0;i<26;++i){
      while(counts[i]-->0)cout<<alphabet[i];
    }
  }else if(counts[lv] -1 <= n/2){
    
    // can do a a b a c a d a ....
    cout<<alphabet[lv];
    --counts[lv];
    if(counts[lv]>0){
      cout<<alphabet[lv];
      --counts[lv];
    }
    int currg = lv +1;
    while(counts[lv]-->0){
      while(counts[currg]==0)++currg;
      
      cout<<alphabet[currg];
      cout<<alphabet[lv];
      --counts[currg];
    }
    for(int i=currg;i<26;++i){
      while(counts[i]-->0)cout<<alphabet[i];
    }
  }
  else if ( nd ==1 ) { // aaaaaaaa
    for(int i=0;i<n;++i)cout<< alphabet[lv];
  } else if ( nd ==2 ){ // abbbbbbbbaaaaaaaaaaa
    cout<<alphabet[lv];
    for(int j=0;j<counts[nlv];++j)cout<<alphabet[nlv];
    for(int k=1;k<counts[lv];++k)cout<<alphabet[lv];
  } else {
    cout<<alphabet[lv];
    cout<<alphabet[nlv];
    --counts[lv];
    --counts[nlv];
    for(int i=0;i<counts[lv];++i){
      cout<<alphabet[lv];
    }
    counts[lv] = 0;
    cout<<alphabet[nnlv];
    --counts[nnlv];
    for(int i=0;i<26;++i){
      while(counts[i]-->0)cout<<alphabet[i];
    }
  }
  cout<<"\n";
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