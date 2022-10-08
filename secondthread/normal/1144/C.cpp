#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n, a[200001], counts[200001]={0};
  cin>>n;
  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<n; i++) counts[a[i]]++;
  for (int i=0; i<200001; i++)
    if (counts[i]>2) {
      cout<<"NO\n";
      return 0;
    }
  cout<<"YES\n";
  vector<int> inc, dec;
  for (int i=0; i<200001; i++) {
    if (counts[i]!=0) {
      counts[i]--;
      inc.push_back(i);
    }
  }
  for (int i=0; i<200001; i++) {
    if (counts[i]!=0) {
      counts[i]--;
      dec.push_back(i);
    }
  }
  cout<<inc.size()<<'\n';
  for (int i=0; i<inc.size(); i++)
    cout<<inc[i]<<' ';
  cout<<'\n'<<dec.size()<<'\n';
  for (int i=dec.size()-1; i>=0; i--)
    cout<<dec[i]<<' ';
  cout<<'\n';

  return 0;
}