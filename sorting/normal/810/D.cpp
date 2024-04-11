#include<iostream>
#include<cstdio>

using namespace std;

int main ()
{
    int n,k,l,r,mid,x,y,z;
    string s;

    cin>>n>>k;

    l=1;
    r=n;

    while(l<r)
    {
        mid=(l+r)/2;
       // cout<<l<<" "<<r<<endl;

        cout<<"1 "<<mid<<" "<<mid+1<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="TAK")
            r=mid;
        else
            l=mid+1;
    }

    x=l;

    l=1;
    r=x-1;

    while(l<r)
    {
        mid=(l+r)/2;

        cout<<"1 "<<mid<<" "<<mid+1<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="TAK")
            r=mid;
        else
            l=mid+1;
    }

    y=l;

    l=x+1;
    r=n;

    while(l<r)
    {
        mid=(l+r)/2;

        cout<<"1 "<<mid<<" "<<mid+1<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="TAK")
            r=mid;
        else
            l=mid+1;
    }

    z=l;

    if(x==1)
    {
        cout<<"2 "<<x<<" "<<z<<endl;
        fflush(stdout);
    }
    else
    {
        if(x==n)
        {
            cout<<"2 "<<y<<" "<<x<<endl;
            fflush(stdout);
        }
        else
        {
            cout<<"1 "<<y<<" "<<z<<endl;
            fflush(stdout);
            cin>>s;
            if(s=="TAK")
            {
                cout<<"2 "<<y<<" "<<x<<endl;
                fflush(stdout);
            }
            else
            {
                cout<<"2 "<<x<<" "<<z<<endl;
                fflush(stdout);
            }
        }
    }

    return 0;
}