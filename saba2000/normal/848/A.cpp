#include<bits/stdc++.h>
using namespace std;
main()
{
string S="a";
int k;
cin>>k;
char s='b'; int u=1000;
while(k>0)
{
    while(u*(u-1)/2>k){u--;}
    k-=u*(u-1)/2;
    for (int i=0; i<u; i++)
        S+=s;
    s++;
}
cout<<S<<endl;
}