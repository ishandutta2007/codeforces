#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

int gcd(int a, int b){
  return b? gcd(b,a%b):a;
}



const int mp = 1000005;
int lp[mp+1];
vector<int> pr;
vector<int> parent(mp,0);
vector<int> sz(mp,1);

int find_set(int v) {
  if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void precomp(){
  // cp=algs linear sieve
  for(int i=0;i<=mp;++i)lp[i] = 0;
  for (int i=2; i<=mp; ++i) {
    make_set(i);
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
        
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=mp; ++j)
        lp[i * pr[j]] = pr[j];
  }
}
vector<int> primedivs(int t){
  vector<int> res;
  while(t>1){
    int p = lp[t];
    res.push_back(p);
    while(t%p==0)t/=p;
  }
  return res;
}
void one(){
  int N,Q;
  cin>>N>>Q;
  vector<int> A(N);
  vector<set<int>> connects(mp);
  for(int i=0;i<N;++i){
    cin>>A[i];
    // cout<<" "<<A[i];
    vector<int> sd = primedivs(A[i]);
    // group primes up with dsu
    for(int i=1;i<sd.size();++i)union_sets(sd[0],sd[i]);
  }
  for(int i=0;i<N;++i){
    int p = find_set(lp[A[i]]);
    vector<int> cd = primedivs(A[i]+1);
    for(int y:cd){
      connects[p].insert(find_set(y));
    }
    for(int i=0;i<cd.size();++i){
      for(int j = 0;j<i;++j){
        connects[find_set(cd[i])].insert(find_set(cd[j]));
        connects[find_set(cd[j])].insert(find_set(cd[i]));
      }
    }
  }
  for(int q=0;q<Q;++q){
    int si,ti;
    cin>>si>>ti;
    --si;--ti;
    int s=A[si];
    int t=A[ti];

    int ps = find_set(lp[s]);
    int pt = find_set(lp[t]);
    if(ps == pt){
      cout<<"0\n";
      continue;
    }
    //iterate over prime divisors
    bool works1=false;
    if(connects[pt].count(ps)==1){
      works1=true;
    }
    if(connects[ps].count(pt)==1){
      works1=true;
    }
    // also have to check if there's some a_i such that a_i+1 is connected to both  
    cout<<(works1?1:2)<<"\n";
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp();
  one();
  cout<<flush;
}