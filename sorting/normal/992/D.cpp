#include<iostream>

using namespace std;

unsigned long long a[200010];
unsigned long long cnt[200010];

int main ()
{
    unsigned long long n,k,i,p,s,j,res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    for(i=0;i<n;i++)
        cin>>a[i];

    if(a[n-1]==1)
        cnt[n-1]=1;
    else
        cnt[n-1]=0;

    for(i=n-2;i<=n;i--)
    {
        if(a[i]==1)
            cnt[i]=cnt[i+1]+1;
        else
            cnt[i]=0;
    }

    for(i=0;i<n;i++)
    {
        p=a[i];
        s=a[i];

        if(p==k*s)
            res++;

        //cout<<i<<" i"<<endl;

        for(j=i+1;j<n;j++)
        {
            //cout<<i<<" "<<j<<" "<<res<<endl;
            //cout<<p<<" "<<s<<" "<<p/s<<endl;
            if(p>k*(s+200000))
                break;
            if(p>(unsigned long long)3000000000000000000/a[j])
                break;
            if(a[j]==1)
            {
                if(p>k*s)
                {
                    s+=cnt[j];
                    if(p<=k*s && p%k==0)
                        res++;
                }
                else s+=cnt[j];


                //cout<<cnt[j]<<" "<<j<<endl;
                j+=cnt[j]-1;

                continue;
            }
            p*=a[j];
            s+=a[j];

            if(p==k*s)
                res++;
        }
        //cout<<"-------------"<<endl;
    }

    cout<<res<<endl;

    return 0;
}
/*
6 1
2 1 2 1 2 1
7
*/