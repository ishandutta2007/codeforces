#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int CT;
  cin>>CT;
  while(CT-->0){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int lastpos=-10000;
    vector<char> r(n,'0');
    for(int i=0;i<n;++i){
      if(s[i]=='1'){
	//fill out another range
	
	if(lastpos!=-10000){
	  for(int j=lastpos+1;j<=min((i+lastpos-1)/2,lastpos+m);++j){
	    r[j]='1';
	  }
	  
	}
	for(int j=max(0, max((lastpos+i+2)/2,i-m));j<=i;++j){
	  r[j]='1';
	}
	lastpos=i;
      }
    }
    if(lastpos!=-10000){
      for(int j=lastpos+1;j<=min(n-1,lastpos+m);++j){
	r[j]='1';
      }
    }
    for(char c:r)cout<<c;
    cout<<endl;
  }
  cout<<flush;
}