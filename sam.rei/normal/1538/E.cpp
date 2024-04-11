#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
struct dat{
  string equiv;
  ll tot;
};
string equivalentshort(string s){
  if(s.size()<4)return s;
  return s.substr(0,3)+'1'+s.substr(s.size()-3,3);
}
dat datify(string s){
  return dat{equivalentshort(s),s.find("haha")==string::npos?0:1};
}
dat combine(dat a,dat b){
  string res = a.equiv + b.equiv;
  ll resval = a.tot+b.tot;
  size_t pos = -1;
  while((pos=res.find("haha",pos+1))!=string::npos){
    ++resval;
  }
  return dat{equivalentshort(res),resval};
}
void one(){
  int n;
  cin>>n;
  string x,t,s,s2;
  map<string,dat> data;
  while(n-->0){
    cin>>x>>t>>s;
    if(t==":="){
      data[x] = datify(s);
    }
    else{
      cin>>t>>s2;
      data[x] = combine(data[s],data[s2]);
    }
  }
  cout<<data[x].tot<<"\n";
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC=0;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}