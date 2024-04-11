#include <iostream>
using namespace std;
int main ()
{int a,b,c,d,e,k;
cin>>a>>b>>c>>d>>e; k=a+b+c+d+e;
if (k%5==0 && k!=0) cout<<k/5<<endl; else cout<<-1<<endl;
return 0;
}