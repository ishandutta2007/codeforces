#include<bits/stdc++.h>
using namespace std;
int a[200214];
main()
{
  string a;
  cin  >> a;
  for (int i=0; i< a.size(); i++)
    cout <<a[i];
  for (int  i =a.size()-1; i>=0; i--)
    cout << a[i] ;
  cout<<endl;
}