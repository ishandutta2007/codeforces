#include<iostream>

using namespace std;

int main ()
{
    long long n,x,n2,y,res=0;

    cin>>n;

    if(n==2)
    {
        cout<<"1"<<endl;
        return 0;
    }

    n--;

    while(n>1)
    {
        x=1;
        y=0;
        n2=n;
        while(n2>1)
        {
            n2>>=1;
            x<<=1;
            y++;
        }

        x>>=1;

        //cout<<x<<endl;
        //cout<<y<<endl;
        res+=(x*y);
       //cout<<res<<endl;

        res+=2*x;

        n-=2*x;
    }

    if(n==1)res++;

    cout<<res<<endl;

    return 0;
}