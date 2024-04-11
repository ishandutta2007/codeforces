#include<bits/stdc++.h>
using namespace std;
int A[1000000];
int B[1000000];
int main()
{
  string a,b;
  cin>>a>>b;
  int t1=0,t2=0;
  for (int i=0;i<a.length();i++)
    if (a[i]!=b[i])
      A[t1++]=a[i],B[t2++]=b[i]; 
  if (a.size()!=b.size() || t1!=2 || t2!=2 || A[0]!=B[1] || A[1]!=B[0])
    cout<<"NO\n";
  else
    cout<<"YES\n";
}