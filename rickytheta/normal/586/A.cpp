#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <complex>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=1;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<n;++i)

int main(){
  int n;
  cin >> n;
  bool inSchool = false;
  bool isBreakOne = false;
  int cnt = 0;
  REP(i,n){
    bool p;
    cin >> p;
    if(p){
      inSchool = true;
      isBreakOne = false;
      ++cnt;
    }else{
      if(isBreakOne){
        --cnt;
        inSchool = false;
        isBreakOne = false;
      }else if(inSchool){
        ++cnt;
        isBreakOne = true;
      }
    }
  }
  if(isBreakOne)--cnt;
  cout << cnt << endl;
  return 0;
}