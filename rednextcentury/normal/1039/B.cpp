#include<bits/stdc++.h>
using namespace std;
bool query(long long l,long long r)
{
    cout<<l<<' '<<r<<endl;
    string ret;
    cin>>ret;
    if (ret=="Yes")return 1;
    if (ret=="Bad")assert(0);
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,k;
    srand(time(NULL));
    cin>>n>>k;
    long long l=1,r=n;
    while(1)
    {
         r=min(r,n);
            l=max(l,1LL);
        while(r-l>60)
        {
            long long mid=(l+r)/2;
            if (query(l,mid))
                l=l-k,r=mid+k;
            else
                l=mid-k,r=r+k;
            r=min(r,n);
            l=max(l,1LL);
        }
        long long rnd = l + rand()%(r-l+1);
        if (query(rnd,rnd))
            return 0;
        l = l-k,r=r+k;
    }
}