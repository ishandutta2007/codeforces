#include<iostream>

using namespace std;

int main ()
{
    long long n,k,m,d;

    cin>>n>>k>>m>>d;

    long long l,r,mid;

    l=1;
    r=m;

    while(l!=r)
    {
        mid=(l+r)/2;

        if((n/mid-1)/k+1<=d)
            r=mid;
        else
            l=mid+1;
    }

    //cout<<l<<endl;

    r=m;

    long long t1,t2,y;

    y=l;


    //cout<<l<<" "<<r<<endl;
    t1=(n/l-1)/k;
    t2=(n/m-1)/k;
    //cout<<t1<<" "<<t2<<endl;

    l=t2;
    r=t1;

    //cout<<r<<" "<<l<<endl;
    while(r-l>1)
    {

        //cout<<l<<" "<<r<<endl;

        mid=(l+r)/2;
        t1=n/(k*l+1);
        t2=n/(k*r+1);
        t1=min(t1,m);
        t2=min(t2,m);

        //cout<<t1<<" "<<t2<<endl;

        if(((n/t1-1)/k+1)*t1<((n/t2-1)/k+1)*t2)
            l=mid;
        else
            r=mid;
    }

    //cout<<l<<" "<<r<<endl;

    t1=n/(k*l+1);
    t2=n/(k*r+1);

    t1=min(t1,m);
    t2=min(t2,m);

    //cout<<t1<<" "<<t2<<endl;

    if(((n/t1-1)/k+1)*t1<((n/t2-1)/k+1)*t2)
            l=r;


    //cout<<l<<endl;

    l=n/(k*l+1);

    l=min(l,m);

    cout<<((n/l-1)/k+1)*l<<endl;

    return 0;
}