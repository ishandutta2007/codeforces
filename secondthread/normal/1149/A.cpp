#include <bits/stdc++.h>

using namespace std;
const int maxn=800001;
int divisors[maxn]={0};

void precomp() {
  for (int i=2; i<maxn; i++) {
    if (divisors[i]!=0)
      continue;
    for (int j=i*2; j<maxn; j+=i) {
      divisors[j]=i;
    }
  }
  divisors[0]=divisors[1]=-1;
}

int main() {
  precomp();
  int n, n1s=0, n2s=0;
  cin>>n;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    if (a==1)
      n1s++;
    else
      n2s++;
  }

  int sum=0;
  for (int i=0; i<n; i++) {
    if (n1s==0||n2s==0) {
      if (n1s==0)
        cout<<2<<" ";
      else
        cout<<1<<" ";
      continue;
    }
    if (divisors[sum+1]==0) {
      cout<<1<<" ";
      n1s--;
      sum++;
    }
    else {
      cout<<2<<" ";
      n2s--;
      sum+=2;
    }
  }
  cout<<endl;
}