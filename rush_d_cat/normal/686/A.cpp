#include<iostream>
#include<cstdio>
using namespace std;
typedef __int64 ll;
int main()
{
    ll n,x,cnt=0;
    char a;int b;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a=='+')
        {
            x+=b;
        }else{
            if(x>=b) x-=b;
            else cnt++;
        }
    }
    cout<<x<<" "<<cnt<<endl;
    return 0;
}