#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,x1,x2,t1,t2;
    cin>>s>>x1>>x2>>t1>>t2;
    int ans=abs(x1-x2)*t2;
    int x,p;
    cin>>x>>p;
    int way;
    int cost=0;
    if (x>=x1 && p==-1)
        way=-1,cost=x-x1;
    else if (x>x1 && p==1)
    {
        way=-1;
        cost=(s-x)+(s-x1);
    }
    else if (x<=x1 && p==1)
        way=1,cost=(x1-x);
    else
        way=1,cost=(x+x1);
    cost*=t1;
    if (x1>=x2 && way==-1)
        way=-1,cost+=(x1-x2)*t1;
    else if (x1>x2 && way==1)
    {
        way=-1;
        cost+=(s-x1)*t1+(s-x2)*t1;
    }
    else if (x1<=x2 && way==1)
        way=1,cost+=(x2-x1)*t1;
    else
        way=1,cost+=(x1+x2)*t1;
    cout<<min(ans,cost)<<endl;
}