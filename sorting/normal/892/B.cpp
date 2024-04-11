#include<iostream>

using namespace std;

int l[1000001],a[1000001];

int main ()
{
    int n,p,cnt=0,i;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
    }

    for(i=n;i>=2;i--)
    {
        if(l[i])
        {
            p=max(1,i-l[i]);

            a[i-1]+=1;
            a[p-1]+=-1;
        }
    }

    p=0;

    for(i=n;i>=1;i--)
    {
        p+=a[i];

        //cout<<a[i]<<endl;

        if(p==0)cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}