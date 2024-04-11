#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
ll vals[4000001];
int lp [4000001];
int M;
int amo(int a, int b){
  int c = a+b;
  return c>=M?c-M:c;
}
int asu(int a,int b){
  int c = a-b;
  return c>=0?c:c+M;
}
int pmo(int a, int b){
  return (int)(a*(ll)b %M);
}
vector<int> divisors(int v){
  vector<int> res;
  if(v==1){res.push_back(1);return res;}
  int t = v;
  int l = lp[v];
  if(l==0)l=v;
  int c = 0;
  while(t%l==0){t/=l;++c;}
  vector<int> ol = divisors(t);
  int os = ol.size();
  for(int i=os;i<os*(c+1);++i){
    ol.push_back(ol[i-os]*l);
  }/*
  for(int i : ol){
    cout<<"D "<<v<<" "<<i<<endl;
    }*/
  // cout<<"S "<<ol.size();
  return ol;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin>>N>>M;
  // cp-algs sieve
  vector<int> pr;
  for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
  }
  vals[0]=0;
  vals[1]=1;
  int cum = 1;
  int prodcum = 0;
  for(int i=2;i<=N;++i){
    int k=2;
    // iterate over divisors of i
    vector<int> div = divisors(i);
    div.pop_back();
    //sort(RANGE(div));
    for(int d : div){
      //cerr<<"d "<<d<<" "<<i<<endl;
      if(d<i)prodcum = amo(prodcum,asu(vals[d],vals[d-1]));
    }
    vals[i] = amo(cum, prodcum);
    cum = amo(cum,vals[i]);
    //cout<<"cum"<<cum<< " "<<prodcum<<endl;
    //cout<<i<<" "<<vals[i]<<endl;
  }
  cout<<vals[N]<<'\n';
  cout<<flush;
}