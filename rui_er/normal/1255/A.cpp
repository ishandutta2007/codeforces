#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int T;
int a,b;
int main()
{
    cin>>T;
    while(T--)
    {
      cin>>a>>b;
      if(a>b)swap(a,b);
      b-=a;
      if(b==1 || b==2 || b==5) cout<<1<<endl;
      else 
      {
        if(b%5==0)cout<<b/5<<endl;
        else cout<<(b-3)/5+2<<endl;;
      }
    }
    return 0;
}