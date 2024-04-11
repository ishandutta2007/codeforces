#include<iostream>
using namespace std;
int maxn,n,t,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int in1,in2;
        cin>>in1>>in2;
        x-=in1-t;
        if(x<0)
            x=0;
        x+=in2;
        maxn=max(maxn,x);
        t=in1;
    }
    cout<<t+x<<" "<<maxn;
    return 0;
}