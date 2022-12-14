#include <bits/stdc++.h>
using namespace std;
long long num[1000];
int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    x++;
    string ret="";
    int p=0;
    if (b>a)p=1;
    while(x>2)
    {
        x--;
        if (p==0)
            ret+="0",a--;
        else
            ret+="1",b--;
        p=1-p;
    }
    if (p)
    {
        while(b)
        {
            b--;
            ret+="1";
        }
        while(a)
        {
            a--;
            ret+="0";
        }
    }
    else
    {
        while(a)
        {
            a--;
            ret+="0";
        }
        while(b)
        {
            b--;
            ret+="1";
        }
    }
    cout<<ret<<endl;
}