#include<iostream>

using namespace std;

int main ()
{
    unsigned long long a,b,res;

    cin>>a>>b;

    if(b-a<=11)
    {
        res=1;
        for(unsigned long long i=a+1;i<=b;i++)
        {
            res*=(i%10);
            res%=10;
        }
    }
    else res=0;

    cout<<res<<endl;

    return 0;
}