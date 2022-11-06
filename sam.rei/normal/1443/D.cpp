#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static int p[200001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
      cin>>p[i];
    }

    
    int maxl = p[0];
    int minr = 0;
    bool works = true;
    for(int i=1;i<n;++i){
      int c = p[i];
      
      if(c>maxl+minr){
	//increase minr, this is safe
	minr = c-maxl;
      }else if(c>=minr){
	maxl = c-minr;
      }
      else{
	works = false;
      }
      //cerr<<minr<<" "<<maxl<<endl;
    }
    cout<<(works?"YES\n":"NO\n");
  }
  cout<<flush;
  return 0;
}