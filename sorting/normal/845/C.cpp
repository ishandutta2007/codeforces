#include<iostream>
#include<algorithm>

using namespace std;

struct duo
{
    int l,r;
};

bool cmp(duo a,duo b)
{
    if(a.l<b.l)return 1;
    if(b.l<a.l)return 0;
    if(a.r<b.r)return 1;
    return 0;
}

duo arr[200000];

int main ()
{
    int n,i,end1,end2;
    bool free1=1,free2=1;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i].l>>arr[i].r;
    }

    sort(arr,arr+n,cmp);

    for(i=0;i<n;i++)
    {
        if(arr[i].l>end1)free1=1;
        if(arr[i].l>end2)free2=1;

        if(free1)
        {
            end1=arr[i].r;
            free1=0;
        }
        else
        {
            if(free2)
            {
                end2=arr[i].r;
                free2=0;
            }
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}