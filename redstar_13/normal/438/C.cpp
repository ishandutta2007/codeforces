#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> Point;
Point operator + (const Point a,const Point b) {return {a.first+b.first,a.second+b.second};}
Point operator - (const Point a,const Point b) {return {a.first-b.first,a.second-b.second};}
Point operator * (const Point a,const int b) {return {a.first*b,a.second*b};}
Point operator / (const Point a,const int b) {return {a.first/b,a.second/b};}
Point operator & (const Point a,const Point b) {return {a.first*b.first-a.second*b.second,a.first*b.second+a.second*b.first};}
LL operator ^ (const Point a,const Point b) {return (LL)a.first*b.second-(LL)a.second*b.first;}
LL operator * (const Point a,const Point b) {return (LL)a.first*b.first+(LL)a.second*b.second;}
bool operator != (const Point a,const Point b) {return a.first==b.first?a.second!=b.second:1;}
Point conj(Point a) {return {-a.second,a.first};}
void Input(Point &a){scanf("%d%d",&a.first,&a.second);}
void Print(Point a){cout<<a.first<<' '<<a.second<<endl;}
int sgn(LL a){return (a>0ll)-(a<0ll);}

const int mod=1e9+7;
const int NN=222;
Point p[NN];
bool is[NN][NN];
int dp[NN][NN];

bool is_on(Point a, Point b, Point c) {
  if (sgn(a-b^b-c)) return 0;
  return sgn((a-c)*(b-c))<=0;
}

bool is_in_poly(Point a, Point *p, int n) {
  for (int i=0; i<n; i++) if (is_on(p[i], p[i+1], a)) return 1;
  int cnt=0;
  for (int i=0; i<n; i++) {
    Point b=p[i], c=p[i+1];
    if (b>c) swap(b, c);
    if (sgn(c-b^a-b)<0 && b.first<a.first && a.first<=c.first) cnt++;
  }
  return cnt&1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n,i,j,k,l,ii,jj,kk,ll;
  scanf("%d",&n);
  for(i=0; i<n; i++) {
    Input(p[i]);
    p[i]=p[i]*2;
  }
  p[n]=p[0];
  LL area=0;
  for(i=0; i<n; i++) area+=p[i]^p[i+1];
  if(area<0) reverse(p,p+n+1);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(i==j) continue;
      is[i][j]=true;
      if(abs(i-j)==1 || abs(i-j)==n-1) {
        continue;
      }
      Point q=(p[i]+p[j])/2;
      if(!is_in_poly(q,p,n)){
        is[i][j]=false;
        continue;
      }
      for(k=0; k<n; k++){
        if(k!=i && k!=j && is_on(p[i],p[j],p[k])){
          is[i][j]=false;
          break;
        }
        ii=sgn(p[k]-p[i]^p[j]-p[i]);
        jj=sgn(p[k+1]-p[i]^p[j]-p[i]);
        kk=sgn(p[i]-p[k]^p[k+1]-p[k]);
        ll=sgn(p[j]-p[k]^p[k+1]-p[k]);
        if(ii && jj && kk && ll && ii!=jj && kk!=ll){
          is[i][j]=false;
          break;
        }
      }
    }
  }
  
  for(i=0; i<n; i++) dp[i][(i+1)%n]=1;
  
  for(k=2; k<n; k++){
    for(i=0; i<n; i++){
      jj=(i+k)%n;
      if(!is[i][jj]) continue;
      for(j=i+1; j<i+k; j++){
        if(is[i][j%n] && is[j%n][jj] && sgn(p[j%n]-p[i]^p[jj]-p[i])){
          dp[i][jj]+=(LL)dp[i][j%n]*dp[j%n][jj]%mod;
          if(dp[i][jj]>=mod) dp[i][jj]-=mod;
        }
      }
    }
  }
  
  cout<<dp[0][n-1]<<endl;
  
  return 0;
}