#include <iostream>

using namespace std;

int main() {
  int n, T;
  cin>>T;
  for (int tt=0; tt<T; tt++) {
    char input[101]={0};
    cin>>input;
    int count[27]={0};
    for (int i=0; input[i]!=0; i++) {
      count[input[i]-'a']++;
    }
    int valid=2;
    for (int i=0; i<26; i++) {
      if (count[i]>1) {
        valid=0;
        //cout<<"character "<<i<<" appears too many times!\n";
      }
      if (count[i]==1&&count[i+1]!=1)
        valid--;
    }
    cout<<(valid==1?"Yes\n":"No\n"); 
  }
  return 0;
}