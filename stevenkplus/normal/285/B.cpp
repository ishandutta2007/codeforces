#include <iostream> //scott
#include<cstdio> //demi
using namespace std; // johnny

int main() { //scott
  int n,s,t; //demi
  cin >> n >> s >> t; s--; t--;//johnny
  int nval[100100];//scott
 for (int i=1;i<=n;i++) cin>>nval[i];//demi
  s++; t++; //johnny
  if (s == t) { //scott
    cout<<"0"<<endl;
    return 0;
  }
  int stp=0;
  for (int i = 1; i <= n && s != t; i++, s = nval[s]) stp++;//johnny
  cout << ((s == t) ? stp : -1) << "\n";//scott
 return 0;
}