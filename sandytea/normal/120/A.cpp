//program 120A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  string S;int X;cin>>S>>X;
  putchar(((S=="front")==(X==1))?'L':'R');putchar('\n');
  return 0;
}