#include <iostream>

using namespace std;

typedef long long ll;
const bool debug=false;
const ll maxn=10;
const ll mod=1000003;
ll modInverse[mod];

ll mult(ll a, ll b) {
  return (a*b%mod+mod)%mod;
}

ll add(ll a, ll b) {
  return ((a+b)%mod+mod)%mod;
}

ll pow(ll a, ll b) {
  ll total=1;
  for (int i=0; i<b; i++)
    total=mult(total, a);
  return total;
}

ll fastPow(ll base, ll exp) {
//  cout<<"calculating fastPow "<<base<<" "<<exp<<endl;
  if (exp==0)
    return 1;
  ll half=fastPow(base, exp/2);
  if ((exp&1)==0)
    return half*half%mod;
  return half*half%mod*base%mod;
}

void precomp() {
  for (int i=1; i<mod; i++) {
//    cout<<"precoming inverse of "<<i<<endl;
    modInverse[i]=fastPow(i, mod-2);
  }
}

ll eval(ll x, ll *poly) {
  ll total=0;
  for (int i=maxn; i>=0; i--) {
    total=(total*x+poly[i])%mod;
  }
  return total;
}

int main() {
  int xs[maxn+1];
  int ys[maxn+1];
  precomp();
  for (int x=0; x<=maxn; x++) {
    xs[x]=x;
    cout<<"? "<<x<<endl;
    cin>>ys[x];
  }
  ll constant=ys[0];
  for (int i=0; i<=maxn; i++)
    ys[i]=add(ys[i], -constant);
  
  ll coefs[maxn+1][maxn];
  for (int x=0; x<maxn; x++) {
    for (int y=0; y<maxn; y++)
      coefs[x][y]=pow(y+1, x+1);
  }
  for (int y=0; y<maxn; y++)
    coefs[maxn][y]=ys[y+1];

  for (int xToClear=0; xToClear<maxn; xToClear++) {
    //cout<<"clearing row "<<xToClear<<endl; 
    /*for (int y=0; y<maxn; y++) {
      for (int x=0; x<=maxn; x++) {
        //cout<<coefs[x][y]<<" ";
        if (x==maxn-1) //cout<<"= ";
      }
      //cout<<endl;
    }*/
    //find a row to clear
    bool found=false;
    for (int startY=xToClear; startY<maxn; startY++) {
      if (coefs[xToClear][startY]!=0) {
        //swap row startY with row xToClear
        for (int x=0; x<=maxn; x++) {
          ll temp=coefs[x][startY];
          coefs[x][startY]=coefs[x][xToClear];
          coefs[x][xToClear]=temp;
        }
        found=true;
        break;
      }
    }
    if (!found) continue;
    //scale this row by modInv
    ll scalar=modInverse[coefs[xToClear][xToClear]];
    for (int x=0; x<=maxn; x++)
      coefs[x][xToClear]=mult(coefs[x][xToClear], scalar);
    //clear all other rows
    for (int yToClear=0; yToClear<maxn; yToClear++) {
      if (xToClear==yToClear) continue;
      ll scalar=-coefs[xToClear][yToClear]+mod;
      for (int x=0; x<=maxn; x++) {
        coefs[x][yToClear]=add(coefs[x][yToClear], mult(coefs[x][xToClear], scalar));
      } 
    }
  }
  ll poly[maxn+1];
  poly[0]=constant;
  for (int i=1; i<=maxn; i++)
    poly[i]=coefs[maxn][i-1];
  //cout<<"found poly: ";
  for (int i=0; i<=maxn; i++)
    //cout<<poly[i]<<" ";
  //cout<<'\n';

 //evaluate for each x
  for (int x=0; x<mod; x++) {
    if (eval(x, poly)==0) {
      cout<<"! "<<x<<'\n';
      return 0;
    }
  }
  
  cout<<"! -1\n";
}