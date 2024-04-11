#include<bits/stdc++.h>
using namespace std;
main()
{
  int n;
  cin>>n;
  int x=0;
  for (int i=1; i<=n; i++)
  {
      x += min(i,n-i+1);

  }
  cout<<x<<endl;
}