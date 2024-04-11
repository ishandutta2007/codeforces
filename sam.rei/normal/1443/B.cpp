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
    int a,b;
    cin>>a>>b;
    string x;
    getline(cin,x);
    getline(cin,x);
    //cout<<x<<" "<<a<<" "<<b<<endl;
    int n = x.length();
    int tot=0;
    int ifs=a;
    bool foundfirst=false;
    bool blowing = false;
    for(int i=0;i <n;++i){
      char c = x[i];
      switch(c){
      case '0':
	blowing = false;
	if(foundfirst)ifs+=b;
	break;
      case '1':
	foundfirst = true;
	if(!blowing){
	  tot+=min(ifs,a);
	  ifs = 0;
	}
	blowing = true;
	break;
      }
    }
    cout<<tot<<endl;
  }
  cout<<flush;
  
  return 0;
}