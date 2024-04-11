#include<iostream>
#include<algorithm>

using namespace std;

long long a[100002];
long long sum[100002];

int main ()
{
    long long n,k,i,j,res=0,num,br=1,beg,end,mid;

    ios::sync_with_stdio(false);

    cin>>n>>k;

    for(i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);

    sum[n-1]=a[n-1];

    for(i=n-2;i>=0;i--)sum[i]=sum[i+1]+a[i];

    for(i=n-2;i>=0;i--)
    {
        if(a[i]!=a[i+1])
        {
            beg=0;
            end=i+1;

            while(beg!=end)
            {
                mid=(beg+end)/2;

                if((i+1-mid)*a[i+1]-sum[mid]+sum[i+1]<=k)
                {
                    end=mid;
                }
                else
                {
                    beg=mid+1;
                }
            }

            //cout<<beg<<endl;

            br+=i+1-beg;


            if(br>=res)
            {
                res=br;
                num=a[i+1];
            }
            br=1;
        }
        else br++;
    }

    if(br>=res)
    {
        res=br;
        num=a[0];
    }

    cout<<res<<" "<<num<<endl;

    return 0;
}