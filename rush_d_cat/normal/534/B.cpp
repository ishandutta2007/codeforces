#include<iostream>
using namespace std;
int main()
{
    int v1,v2,t,d;cin>>v1>>v2>>t>>d;
    if(d==0)
    {
        cout<<v1*t<<endl;
    }else{
        int res=v1;int v=v1;
        for(int i=2;i<=t;i++)
        {

            if(v2+(t-i)*d>=v+d)
            {
                v+=d;
                res+=v;
            }else{
                v=v2+(t-i)*d;
                res+=v;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}