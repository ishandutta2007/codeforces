#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int a=-1,b=-1,c=-1,d=-1;
int main()
{
    int m,n;
    cin>>m>>n;
    if(m>n)
        swap(m,n);
    c=m/__gcd(m,n),d=n/__gcd(m,n);
    m=__gcd(m,n);
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            if(i*i+j*j==m*m)
            {
                a=i;
                b=j;
                break;
            }
    if(a==-1)
    {
        cout<<"NO";
        return 0;
    }
    if(c*b!=a*d)
    {
        cout<<"YES"<<endl;
        cout<<"0 0\n";  
        cout<<c*a<<' '<<c*b<<endl;
        cout<<-b*d<<' '<<a*d<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<"0 0\n";  
        cout<<c*a<<' '<<-c*b<<endl;
        cout<<b*d<<' '<<a*d<<endl;      
    }
}