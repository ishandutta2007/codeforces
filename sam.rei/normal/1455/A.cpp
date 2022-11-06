#include "bits/stdc++.h"

using namespace std;

static int a[100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  string s;
  getline(cin,s);
  while(ct-->0){
    getline(cin,s);
    cout<<s.size()<<endl;
  }
  cout<<flush;
}