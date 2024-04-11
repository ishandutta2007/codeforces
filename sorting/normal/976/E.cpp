#include<iostream>
#include<algorithm>

using namespace std;

long long hp[200001],dmg[200001];
pair<long long,long long> q[200001];

int main ()
{
    long long a,b,n,maxi=0,sum=0,p,i;

    cin>>n>>a>>b;

    if(b>n)b=n;

    for(i=0;i<n;i++)
    {
        cin>>hp[i]>>dmg[i];
    }

    for(i=0;i<n;i++)
    {
        q[i].first=hp[i]-dmg[i];
        if(q[i].first<0)q[i].first=0;
        q[i].second=i;
    }

    sort(q,q+n);

    for(i=n-1;i>=0 && i>=n-b;i--)
    {
        sum+=q[i].first;
    }
    for(i=n-1;i>=0;i--)
        sum+=dmg[i];

    if(a!=0)a=1<<a;

    if(b==0)
    {
        cout<<sum<<endl;
        return 0;
    }

    for(i=n-1;i>=0 && q[i].first!=0 && i>=n-b;i--)
    {
        //cout<<i<<endl;
        p=(a-1)*hp[q[i].second];
        if(p>maxi)
        {
            maxi=p;
        }
    }
    for(i;i>=0;i--)
    {
        //cout<<maxi<<endl;
        p=a*hp[q[i].second]-dmg[q[i].second]-q[n-b].first;
        maxi=max(p,maxi);
    }

    if(a==0)
        maxi=0;

    //cout<<maxi<<" "<<sum<<endl;

    cout<<maxi+sum<<endl;

    return 0;
}
/*
3 2 2
6 3
4 10
7 20
*/