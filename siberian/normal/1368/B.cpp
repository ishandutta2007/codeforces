#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli power(lli a,lli b)
{
  if(b==0) return 1;
  lli t=power(a,b/2);
  t*=t;
  if(b%2) t=t*a;
  return t;
}
int main()
{
  lli n;
  cin>>n;
  int no;
  if(n==1) cout<<"codeforces \n";
  else
  {
    for(int i=2;i<=40;i++)
    {
      if(power(i,10)>=n)
      {
        no=i;
        break;
      }
    }
  //  cout<<no;
    int p=10,q=0;
 
    for(int i=1;i<=10;i++)
    {
      if((power(no,i)*power(no-1,10-i))>=n)
      {
        p=i;
        q=10-i;
        break;
      }
    }
  //  cout<<p<<" "<<q;
    string s="codeforces";
    string ans="";
    for(int i=0;i<p;i++)
    {
      for(int j=0;j<no;j++)
      {
        ans+=s[i];
      }
    }
    for(int i=p;i<10;i++)
    {
      for(int j=0;j<(no-1);j++)
      {
        ans+=s[i];
      }
    }
   cout<<ans<<endl;
  }
 
 
}