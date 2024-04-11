#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
vector<pair<in,in> > antp;
VI endv;
in m;
in nr(in a){
  a%=m;
  if(a<0)
    a+=m;
  return a;
}
VI res;
int main(){
  in n,t;
  //cin>>n>>m>>t;
  scanf("%I64d %I64d %I64d", &n, &m, &t);
  antp.resize(n);
  char d[5];
  res.resize(n);
  in totm=0;
  forn(i,n){
    //cin>>antp[i].first;
    scanf("%I64d", &antp[i].first);
    antp[i].second=i;
    //cin>>d;
    scanf("%s", d);
    if(d[0]=='L'){
      totm-=t;
      totm%=n*m;
      endv.PB(nr(antp[i].first-t));
    }
    else{
      totm+=t;
      totm%=n*m;
      endv.PB(nr(antp[i].first+t));
    }
  }
  totm%=n*m;
  if(totm<0)
    totm+=n*m;
  sort(all(antp));
  sort(all(endv));
  forn(i,n)
    totm+=antp[i].first;
  forn(i,n)
    totm-=endv[i];
  totm%=n*m;
  if(totm<0)
    totm+=n*m;
  assert(totm%m==0);
  in cc=totm/m;
  forv(i,antp)
    res[antp[i].second]=endv[(i+cc)%n];
  forv(i,res)
    cout<<(res[i]==0?m:res[i])<<" ";
  cout<<endl;
  return 0;
}