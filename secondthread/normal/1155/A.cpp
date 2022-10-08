#include <iostream>

using namespace std;
const int maxn=300001;
char array[maxn];

int main() {
  int n;
  cin>>n;
  cin>>array;
  for (int i=0; i+1<n; i++) {
    if (array[i]>array[i+1]) {
      cout<<"YES\n"<<i+1<<" "<<i+2<<"\n";
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;
}