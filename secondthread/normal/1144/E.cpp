#include <iostream>
#define maxn 300001
using namespace std;

int a[maxn]={0}, b[maxn]={0};
char wordA[maxn]={0}, wordB[maxn]={0};
int sum[maxn]={0};
int main() {
  int n;
  cin>>n>>wordA>>wordB;
  for (int i=0; i<n; i++) {
    a[i]=wordA[n-1-i]-'a';
    b[i]=wordB[n-1-i]-'a';
  }
  for (int i=0; i+1<maxn; i++) {
    sum[i]+=a[i]+b[i];
    int above=sum[i]/26;
    sum[i+1]+=above;
    sum[i]-=26*above;
  }
  //divide by 2
  for (int i=0; i<maxn; i++) {
    if (sum[i]%2==0) {
      sum[i]/=2;
    }
    else {
      sum[i]/=2;
      sum[i-1]+=26/2;
    }
  }
  for (int i=0; i+1<maxn; i++) {
    int above=sum[i]/26;
    sum[i+1]+=above;
    sum[i]-=26*above;
  }
  for (int i=n-1; i>=0; i--) {
    char toPrint=sum[i]+'a';
    cout<<toPrint;
  }
  cout<<'\n';
}