#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n,s;
      cin>>n>>s;
      int t=s/n;
      if (s%n>0) t++;
      cout<<t<<endl;
}