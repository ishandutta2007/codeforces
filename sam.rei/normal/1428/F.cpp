#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll values[500001];
//static ll runs[500001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  
  cin >>n;
  std::string s;
  cin>>s;
  vector<int> stack;
  ll res = 0;
  ll cv  = 0;
  int cr = 0;
  //for(int i=0;i<=n;++i)values[i]=i-2;
  for(int i=0;i<n;++i){
    switch(s[i]){
    case '0':
      if(cr>0&&i>0){
	stack.push_back(i-1);
      }
      cr=0;
      break;
    case '1':
      ++cr;
      if(stack.size()>0){
	int old = stack.back();
	cv += i-old+cr-1;
	if(values[old]==cr)stack.pop_back();
      }
      else{
	cv += i+1;
      }
    }
    //    runs[i]=cr;
    values[i] = cr;
    res+=cv;
    //cerr<<cv<<endl;
  }
  cout<<res<<endl;
  return 0;
}