#include<bits/stdc++.h>
using namespace std;
int main()
{int a,b,p,q,x,y;
cin>>a>>b>>p>>q>>x>>y;
if((p-a)%x==0 &&
(q-b)%y==0 && ((p-a)/x+(q-b)/y)%2==0) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}