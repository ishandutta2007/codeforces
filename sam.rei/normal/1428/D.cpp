#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
static int counts[100001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >>n;
  int cx=1;
  int cy=1;
  queue<int> doubles;
  int ltripley=0;
  std::vector<std::pair<int,int>> booms;
  for(int i = 0; i<n;++i){
    int c;
    cin>>c;
    switch(c){
    case 0:
      //++cx;
      break;
    case 1:      
      if(!doubles.empty()){
	booms.emplace_back(cx,doubles.front());
	doubles.pop();
      }
      else{
	if(ltripley!=0){
	  booms.emplace_back(cx,ltripley);
	  ltripley=0;
	}
	booms.emplace_back(cx,cy);
	++cy;
      }
      break;
    case 2:
      //     ldoubley = x

      if(ltripley!=0){
	booms.emplace_back(cx,ltripley);
	ltripley=0;
      }
      booms.emplace_back(cx,cy);
      doubles.push(cy);
      
      ++cy;
      break;
    case 3:
      if(ltripley!=0){
	booms.emplace_back(cx,ltripley);
	ltripley=0;
      }
      booms.emplace_back(cx,cy);
      ltripley=cy;
      ++cy;
      break;
    }
    ++cx;
  }
  if(doubles.empty() && ltripley ==0){
    cout<<booms.size()<<'\n';
    for(auto b:booms){
      cout<<b.second<<" "<<b.first<<'\n';
    }
    cout<<flush;
  }
  else {
      cout<<"-1\n"<<flush;  
  }
  return 0;
}