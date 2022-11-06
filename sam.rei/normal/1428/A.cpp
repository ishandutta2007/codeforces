#include "bits/stdc++.h"

using namespace std;
static int w[100000];
int main(){
  int n,x1,x2,y1,y2;
  cin>>n;
  while(n-->0){
    cin>>x1>>y1>>x2>>y2;
    
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    int r=dx+dy;
    if(dx>0 &&dy > 0) r+=2;
    cout<<r<<"\n";
  }
  cout<<flush;
}