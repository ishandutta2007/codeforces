#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

int main() {
  int n, nEvens=0, nOdds=0, a[2001], evens[2001], odds[2001];
  cin>>n;
  for (int i=0; i<n; i++)
    cin>>a[i];
  sort(a, a+n);
  //cout<<"After sorting, a: ";
  //for (int i=0; i<n; i++)
    //cout<<a[i]<<" ";
  //cout<<'\n';
  for (int i=0; i<n; i++) {
    if (a[i]%2==0)
      evens[nEvens++]=a[i];
    else
      odds[nOdds++]=a[i];
  }
  ll total=0;
  if (nEvens>nOdds) {
    for (int i=0; i+1<nEvens-nOdds; i++)
      total+=evens[i];
  }
  else {
    for (int i=0; i+1<nOdds-nEvens; i++)
      total+=odds[i];
  }
  cout<<total<<'\n';
}