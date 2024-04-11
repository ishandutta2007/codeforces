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
    int n;
    cin>>n;
    int k=n-1;
    int s = k-n+1;
    while(true){
      k+=1;
      s=k-n+1;
      //check if k is prime, and s is composite
      bool p=true,c=false;
      if(s==1)c=true;
      for(int j=2;j*j<=k;++j){
	if(s%j==0&&j<s)c=true;
	if(k%j==0&&j<k)p=false;
      }
      if(c & p) break;
    }
    
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
	if(i==j)cout<<s;
	else cout<<'1';
	if(j==n-1)cout<<'\n';
	else cout<<' ';
      }
    }
  }
  cout<<flush;
  
  return 0;
}