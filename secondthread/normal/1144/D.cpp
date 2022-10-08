#include <iostream>
#include <vector>
#define MAXN 200001
using namespace std;

int main() {
  int n, a[MAXN], freq[MAXN]={0};
  cin>>n;
  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<n; i++) freq[a[i]]++;
  int maxFreq=0;
  for (int i=0; i<MAXN; i++)
    if (freq[i]>freq[maxFreq])
      maxFreq=i;

  int turns=n-freq[maxFreq];
  cout<<turns<<'\n';
  int startIndex;
  for (int i=0; i<n; i++)
    if (a[i]==maxFreq)
      startIndex=i;

  for (int i=startIndex-1; i>=0; i--) {
    if (a[i]<maxFreq) {
      cout<<"1 "<<i+1<<' '<<i+2<<'\n';
    }
    else if (a[i]>maxFreq) {
      cout<<"2 "<<i+1<<' '<<i+2<<'\n';
    }
  }
  for (int i=startIndex+1; i<n; i++) {
    if (a[i]<maxFreq) {
      cout<<"1 "<<i+1<<' '<<i<<'\n';
    }
    else if (a[i]>maxFreq) {
      cout<<"2 "<<i+1<<' '<<i<<'\n';
    }
  }

  return 0;
}