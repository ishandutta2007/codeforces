#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sq(x) ((x)*(x))
using namespace std;
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;

const int inf=0x3f3f3f3f,mod=1000000007;
const INT INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.),eps=1e-9;

const int NN=500500;
void add(int &a,int b){a+=b;if(a>=mod) a-=mod;}
void add(int &a,INT b){a+=b;if(a>=mod) a-=mod;}

int B[2][NN];
pii p[NN];
int a[NN];
int ans[NN];

void update(int id,int u,int d){
  if(!id){
    while(u<NN){
      add(B[id][u],d);
      u+=u&-u;
    }
  }else{
    while(u>0){
      add(B[id][u],d);
      u-=u&-u;
    }
  }
}

int calc(int id,int u,int ans=0){
  if(!id){
    while(u>0){
      add(ans,B[id][u]);
      u-=u&-u;
    }
  }else{
    while(u<NN){
      add(ans,B[id][u]);
      u+=u&-u;
    }
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++){
    scanf("%d",a+i);
    p[i].x=a[i];
    p[i].y=i;
  }
  
  sort(p+1,p+n+1);
  for(int i=1; i<=n; i++){
    int tmp1,tmp2;
    add(ans[p[i].y],(INT)(n-p[i].y+1)*(calc(0,p[i].y))%mod);
    add(ans[p[i].y],(INT)(p[i].y)*calc(1,p[i].y)%mod);
    add(ans[p[i].y],(INT)(p[i].y)*(n-p[i].y+1)%mod);
    update(0,p[i].y,p[i].y);
    update(1,p[i].y,n-p[i].y+1);
  }
  
  int Answer=0;
  for(int i=1; i<=n; i++){
    add(Answer,(INT)ans[i]*a[i]%mod);
  }
  
  cout<<Answer<<endl;
  
  return 0;
}