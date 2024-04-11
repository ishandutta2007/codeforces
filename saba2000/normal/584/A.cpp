#include <iostream>
using namespace std;
int main ()
{int n,t;
cin>>n>>t;
if (t!=10) {cout<<t; for(int i=1; i<n; i++) cout<<0;} else 
if (n==1) cout<<-1; else {cout<<1; for (int i=1; i<n; i++) cout<<0;}
cout<<endl;
return 0;
}