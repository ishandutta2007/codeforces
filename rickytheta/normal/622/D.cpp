#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

void naive(int n){
  vi a(2*n);
  REP(i,n) a[2*i] = a[2*i+1] = (i+1);
  // O(NNN!)
  vi res = a;
  int minsum = 1145141919;
  do{
    int s = 0;
    REP(i,2*n){
      int v = a[i];
      REP(j,2*n){
        if(i==j)continue;
        if(a[j]==v){
          s += (n-v)*abs(abs(j-i)+v-n);
          break;
        }
      }
    }
    if(s<minsum){
      minsum = s;
      res = a;
      if(s==0)break;
    }
  }while(next_permutation(ALL(a)));
  DEBUG(minsum);
  DEBUG_VEC(res);
}

int main(){
  int n;
  scanf("%d",&n);
  // naive(n);
  int res[2*n];
  int iter=0;
  if(n%2==0){
    for(int v=1;v<n;v+=2){
      res[iter++]=v;
    }
    for(int v=n-1;v>0;v-=2){
      res[iter++]=v;
    }
    for(int v=2;v<n;v+=2){
      res[iter++]=v;
    }
    res[iter++]=n;
    for(int v=n-2;v>0;v-=2){
      res[iter++]=v;
    }
    res[iter++]=n;
  }else{
    for(int v=1;v<n;v+=2){
      res[iter++]=v;
    }
    res[iter++]=n;
    for(int v=n-2;v>0;v-=2){
      res[iter++]=v;
    }
    for(int v=2;v<n;v+=2){
      res[iter++]=v;
    }
    for(int v=n-1;v>0;v-=2){
      res[iter++]=v;
    }
    res[iter++]=n;
  }

  // check
  // int s = 0;
  // REP(i,2*n){
  //   int v = res[i];
  //   REP(j,2*n){
  //     if(i==j)continue;
  //     if(res[j]==v){
  //       s += (n-v)*abs(abs(j-i)+v-n);
  //       break;
  //     }
  //   }
  // }
  // DEBUG(s);

  printf("%d",res[0]);
  REPR(i,2*n)printf(" %d",res[i]);
  printf("\n");
  return 0;
}