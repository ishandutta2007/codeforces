#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
static bool reach[300001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int a;
    cin>>a;
    int s = 0;
    int c = 0;
    while(c<a){
      ++s;
      c+=s;
    }
    if(c!=a){
      if(c==a+1)++s;
    }
    cout<<s<<endl;
  }
  cout<<flush;
  
  return 0;
}