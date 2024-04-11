#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll values[100001];
static int phi[100001];
//static ll runs[500001];
static ll p = 998244353;
static bool sqf[100001];

ll exp2(ll a){
  if(a==0)return 1;
  if(a==1)return 2;
  ll b = exp2(a/2);
  ll c = (b*b)%p;
  if(a%2==1)return (c*2)%p;
  else return c;  
}

int main(){
  constexpr int N=100000;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m;
  cin>>m;
  ll n = 0;
  while(m-->0){
    int k;ll f;
    cin>>k>>f;
    values[k]=f;
  }
  fill(sqf,sqf+100001,true);
  fill(phi,phi+100001,0);
  phi[1]=2;
  ll r =0;
  for(int d=1;d<=N;++d){
    ll n = 0;
    ll ss= 0;
    ll s = 0;
    if(!sqf[d])continue;
    if(phi[d]==0){
      for(int j=d;j<=N;j+=d){
	++phi[j];
      }
      if(d<=N/d){
	int c = d*d;
	for(int j=c;j<=N;j+=c){
	  sqf[j]=false;
	}
      }
    }
    for(int j=d;j<=N;j+=d){
      n=n+values[j];
      s=(s+values[j]*j)%p;
      ss=(ss+((values[j]*j)%p)*j)%p;
    }
    if(n<=1)continue;
    ll p2 = exp2(n-3);
    if(n==2) p2 = (p+1)/2;
    ll subsum = ((((p2*(n%p))%p)*s)%p*s)%p + (((p2*((n-2)%p))%p)*ss)%p;
    if(phi[d]%2 == 1){
      r-=subsum;
    }
    else{
      r+=subsum;
    }
    //cout<<d<<" "<<subsum<<" "<<phi[d]<<endl;
    
  }
  cout<< (r%p +p)%p <<endl;
  return 0;
}