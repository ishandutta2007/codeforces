#include<iostream>

using namespace std;

int main ()
{
    long long n,a,b,sum=0,b1=0,b2=0;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }


    for(int i=0;i<n;i++)
    {
        cin>>b;

        if(b>b1)
        {
            b2=b1;
            b1=b;
        }
        else
        {
            if(b>b2)
            {
                b2=b;
            }
        }
    }

    if(sum<=b1+b2)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}