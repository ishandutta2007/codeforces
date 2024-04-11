#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin>>ct;
  while(ct-->0){
    int n,x;
    vector<int> a;
    vector<int> b;
    cin>>n>>x;
    for(int i=0;i<n;++i){
      int f;
      cin>>f;
      a.push_back(f);
      b.push_back(f);
    }
    bool sorted=true;
    int firstmiss=n-1;
    for(;firstmiss>0;--firstmiss){
      if(a[firstmiss]<a[firstmiss-1]){sorted=false;break;}
    }
    if(sorted){
      cout<<0<<endl;
      continue;
    }
    b.push_back(x);
    sort(b.begin(),b.end());
    int c = 0;
    bool works=true;
    int xub= 100000000;
    int xlb = -7;
    for(int i=0;i<firstmiss;++i){
      //see if we have to change
      if(b[i] != a[i]){
	if(b[i] != x){
	  //check if the rest work
	  works = false;
	  break;
	}
	//force a[i] = x;
	x= a[i];
	++c;
      }
    }
    if(!works)c=-1;
    cout<<c<<endl;
  }
  cout<<flush;
  return 0;
}