#include <iostream>
using namespace std;
int main ()
{int x,y,t;
cin>>x>>y; t=abs(x)+abs(y);
if (x>0 && y>0) cout<<"0 "<<t<<" "<<t<<" "<<0<<endl; else
if (x<0 && y>0) cout<<-t<<" 0 "<<"0 "<<t<<endl; else
if (x>0 && y<0) cout<<"0 "<<-t<<" "<<t<<" "<<0<<endl; else
if (x<0 && y<0) cout<<-t<<" 0"<<" 0 "<<-t<<endl;
return 0;
}