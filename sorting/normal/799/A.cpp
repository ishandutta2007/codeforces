#include<iostream>

using namespace std;

int main ()
{
    int n,k,t,d,p1,p2,p3;

    ios::sync_with_stdio(false);

    cin>>n>>t>>k>>d;

    if(n%k==0)
    {
        p1=(n/k)*t;
    }
    else
    {
        p1=(n/k+1)*t;
    }

    if(p1<=d)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    n-=(d/t)*k;

    p3=n/k;

    if(n%k!=0)p3++;

    //cout<<p3<<endl;

    if(p3%2==0)
    {
        p2=d+(p3/2)*t;
    }
    else
    {
        p2=d+(p3+1)/2*t-(d%t);
    }

    //cout<<p1<<" "<<p2<<endl;

    if(p1<=p2)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    return 0;
}