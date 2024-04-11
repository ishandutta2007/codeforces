#include <iostream>
#include<string>
using namespace std;
int main ()
{
    string a,b;
    int l=0,m=0,k[256]={0};
    cin>>a>>b;
    for (int i=0; i<b.length(); i++)
    k[(int)b[i]]++;
    for (int i=0; i<a.length(); i++)
    if (k[a[i]]>0) {l++; k[a[i]]--; a[i]=0;}
    for (int i=0; i<a.length(); i++)
    {if (a[i]!=0)  if (a[i]<97) {if (k[a[i]+32]>0) {m++; k[a[i]+32]--;}}
    else if(k[a[i]-32]>0) {m++; k[a[i]-32]--;} }
    cout<<l<<" "<<m<<endl;
    //system ("pause");
    return 0;

}