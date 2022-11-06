#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
static bool reach[300001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >>t;
  
  //cout<<n<<endl;
  int k;
  string s;
  getline(cin,s);
  while(t-->0){
    getline(cin,s);
    int k = s.length();
    int sb=0;
    int ac=0;
    int bc=0;
    int fa=0;
    for(int i=0;i<k;++i){
      switch(s[i]){
      case 'A':
	++ac;
	break;
      case 'B':
	if(ac)--ac;
	else ++bc;
	break;
      default:
	break;
      }
    }
    cout<<ac+(bc%2)<<endl;
  }
  cout<<flush;
  return 0;
}