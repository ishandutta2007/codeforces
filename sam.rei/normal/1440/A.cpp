#include "bits/stdc++.h"

using namespace std;

static int a[100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int n,c,d,h;
    cin>>n>>c>>d>>h;
    string s;
    getline(cin,s);
    getline(cin,s);
    int a=0;
    for(char e:s){
      if(e=='0'){
	a+=min(c,d+h);
      }
      if(e=='1'){
	a+=min(d,c+h);
      }
    }
    cout<<a<<endl;
  }
  cout<<flush;
}