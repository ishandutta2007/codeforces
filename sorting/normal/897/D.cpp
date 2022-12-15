#include<iostream>
#include<stdio.h>

using namespace std;

int a[1004];
int l,r;

int binary_search_lower(int l,int r,int val)
{
    int mid;

    while(l!=r)
    {
        mid=(l+r)/2;
        if(a[mid]>val)
        {
            r=mid;
        }
        else l=mid+1;
    }

    return l;
}

int binary_search_higher(int l,int r,int val)
{
    int mid;

    while(r-l>1)
    {

        //cout<<r<<" "<<l<<endl;
        mid=(l+r)/2;
        if(a[mid]<val)
        {
            l=mid;
        }
        else r=mid-1;
    }

    if(a[r]<val)return r;

    return l;
}

int main ()
{
    int n,m,c,i,p,t;

    cin>>n>>m>>c;

    a[0]=1;
    l=1;
    r=n;
    a[n+1]=c;

    for(i=0;i<m;i++)
    {
        if(l>r)break;
        cin>>p;

        if(p<a[l-1])
        {
            t=binary_search_lower(1,l-1,p);
            a[t]=p;
            cout<<t<<endl;

            fflush(stdout);

            continue;
        }
        if(p>a[r+1])
        {
            t=binary_search_higher(r+1,n,p);
            a[t]=p;
            cout<<t<<endl;

            fflush(stdout);

            continue;
        }
        if(p>(c+1)/2)
        {
            a[r]=p;
            cout<<r<<endl;
            r--;


            fflush(stdout);
        }
        else
        {
            a[l]=p;
            cout<<l<<endl;
            l++;

            fflush(stdout);
        }
    }

    return 0;
}