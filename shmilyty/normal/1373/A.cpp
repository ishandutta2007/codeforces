#include<bits/stdc++.h>
using namespace std;
int t;
double a,b,c;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b>>c;
        if(a>=c)
            cout<<-1<<" ";
        else
            cout<<1<<" ";
        double x=c/b;
        if(x>=a)
            cout<<-1<<endl;
        else
            cout<<(int)b<<endl;
    }
    return 0;
}