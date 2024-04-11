#include<iostream>
#include<algorithm>

using namespace std;

int main ()
{
    long long n,k,sum=0,i,x,mini,p;
    long double d;

    ios::sync_with_stdio(false);

    cin>>n>>k;

    mini=n-k+1;

    for(i=0;i<n;i++)
    {
        cin>>x;

        if(k-i-2>=0)
        {
            p=min(i+1,mini);
            sum+=x*p;
        }
        else
        {
            if(n-i<k)
            {
                p=min(n-i,mini);
                sum+=x*p;
            }
            else
            {
                p=min(mini,k);
                sum+=x*p;
            }
        }
    }

    cout.precision(8);

    d=(double)sum/(n-k+1);

    cout<<fixed<<d<<endl;

    return 0;
}