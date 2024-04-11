//program 151A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int n,k,l,c,d,p,nl,np;
  cin>>n>>k>>l>>c>>d>>p>>nl>>np;
  cout<<min(min(k*l/nl,c*d),p/np)/n<<endl;
  return 0;
}