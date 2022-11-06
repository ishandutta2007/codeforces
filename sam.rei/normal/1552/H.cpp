#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,set<int>> poss(set<int>& shortpos,int t,int d){
  map<int,set<int>> possibilities;
      for(int j : shortpos){
        int v = ((d/j)/t)*(j/t);
        possibilities.emplace(v,set<int>());
        possibilities[v].insert(j);
        if(j%t!=0){
          if( (d/j)%t!=0){
            v = ((d/j)/t +1)*(j/t+1);
            possibilities.emplace(v,set<int>());
            possibilities[v].insert(j);
          }
          v = ((d/j)/t)*(j/t+1);
          possibilities.emplace(v,set<int>());
          possibilities[v].insert(j);
          
        }
        if( (d/j)%t!=0){
          v = ((d/j)/t +1)*(j/t);
          possibilities.emplace(v,set<int>());
          possibilities[v].insert(j);
        }
      }

      return possibilities;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  vector<int> counts(40001,1);
  cout<<"? 40000\n";
  for(int i=1;i<=200;++i){
    for(int j=1;j<=200;++j){
      cout<<i<<" "<<j<<(" \n"[i==200 && j==200]);
    }
  }
  cout<<flush;
  // find least divisor
  int d;
  cin>>d;
  set<int> shortpos;
  vector<int> divs;
  vector<bool>isprime;
  for(int i=1;i<=200;++i){
    if(i*i>d)break;
    if(d%i ==0 && d/i<=200){
      shortpos.insert(i);
    }
    
  }
  while(shortpos.size()>1){
    int bestval = 30;
    int bestt = 0;
    map<int,set<int>> pos;
    for(int t=2;t<=200;++t){
      int ma = 0;
      auto paaa = poss(shortpos,t,d);
      for(auto p:paaa){
        ma = max(ma,(int)p.second.size());
      }
      if(ma<bestval){
        bestval = ma;
        bestt=t;
        pos = paaa;
      }
      // find largest possibilities, be in pain.
      
    }
    
    // guess t
    int t = bestt;
    cout<<"? "<<(200/t)*(200/t)<<"\n";
    for(int i=t;i<=200;i+=t){
      for(int j=t;j<=200;j+=t){
        cout<<i<<" "<<j<<" ";
      }
    }
    // for(int i:shortpos){
    //cout<<i<<" ";
    //}
    //cout<<endl;
    assert(bestval<shortpos.size());
    
    cout<<"\n";
    cout<<flush;
    int res;
    cin>>res;
    shortpos = pos[res];
  }
  /*
  int ma =0;
  for(int i=0;i<=40000;++i){
    int c = counts[i];
    if(ma<c){
             
    }ma=max(ma,c);
    }*/
  int shortside = *shortpos.begin();
  cout<<"! "<<2*(shortside+d/shortside-2)<<endl;
}