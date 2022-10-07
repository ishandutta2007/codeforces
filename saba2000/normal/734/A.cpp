#include<iostream>
using namespace std;
main()
{int n,x=0,y=0; string a;
cin>>n>>a;
for (int i=0; i<a.length(); i++)
if (a[i]=='A') x++;else y++;
if (x>y) cout<<"Anton"<<endl; else if (x<y) cout<<"Danik"<<endl;
else cout<<"Friendship"<<endl;

}