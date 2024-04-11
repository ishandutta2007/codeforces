#include<iostream>
#include<algorithm>

using namespace std;

long long a[200001];
long long b[200001];

int main ()
{
    long long n,q,i,l,r,curr=0;
    long long res=0;

    ios::sync_with_stdio(false);

    cin>>n>>q;

    for(i=1;i<=n;i++)cin>>a[i];

    for(i=0;i<q;i++)
    {
        cin>>l>>r;

        if(r!=n)
        {
            b[l]++;
            b[r+1]--;
        }
        else b[l]++;
    }
    for(i=1;i<=n;i++)
    {
        curr+=b[i];
        b[i]=curr;
    }

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    for(i=n;i>=1 && b[i]!=0;i--)
    {
        //cout<<b[i]<<" "<<a[i]<<endl;
        res+=b[i]*a[i];
    }

    cout<<res<<endl;

    return 0;
}