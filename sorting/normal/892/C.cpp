#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b,a%b);
}

int a[2001];
int b[2001];
int c[2001];

int main ()
{
    int n,p,cnt=0,i,j;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];

        if(a[i]==1)
            cnt++;
    }

    if(cnt)
    {
        cout<<n-cnt<<endl;
        return 0;
    }

    for(i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            for(j=1;j<=n-i+1;j++)
            {
                c[j]=gcd(b[j],a[j+i-1]);
                //cout<<c[j]<<endl;
                if(c[j]==1)
                {
                    cout<<i+n-2<<endl;
                    return 0;
                }
            }
        }
        else
        {
            for(j=1;j<=n-i+1;j++)
            {
                b[j]=gcd(c[j],a[j+i-1]);
                //cout<<b[j]<<endl;
                if(b[j]==1)
                {
                    cout<<i+n-2<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"-1"<<endl;

    return 0;
}