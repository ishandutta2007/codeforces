#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const long long M=100007;
const long long mod=1000000007;

pair<long long,long long> p[M];
long long arr[M],prefix[M];
long long cnt=0;

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.second<b.second)
        return 1;
    if(b.second<a.second);
        return 0;
    return a.first<b.first;
}

long long binary_Search(long long val)
{
    long long l,r,mid;

    l=0;
    r=cnt;

    while(l!=r)
    {
        mid=(l+r)/2;

        if(arr[mid]>=val)
            r=mid;
        else
            l=mid+1;
    }

    return l;
}

long long sum(long long l, long long r)
{
    if(l==0)
        return prefix[r]%mod;

    long long res;

    res=(prefix[r]-prefix[l-1]);
    res%=mod;

    while(res<0)res+=mod;

    return res;
}

int main ()
{
    long long n,m,i,t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(i=0;i<m;i++)
        cin>>p[i].first>>p[i].second;

    sort(p,p+m,cmp);

    cnt=1;
    arr[0]=0;
    prefix[0]=1;

    for(i=0;i<m;i++)
    {
        if(p[i].second==arr[cnt-1])
        {
            t=binary_Search(p[i].first);
            prefix[cnt-1]=(sum(t,cnt-2)+prefix[cnt-1])%mod;
            continue;
        }

        t=binary_Search(p[i].first);
        arr[cnt]=p[i].second;
        prefix[cnt]=(sum(t,cnt-1)+prefix[cnt-1])%mod;
        cnt++;
    }

    if(arr[cnt-1]!=n)
    {
        cout<<"0"<<endl;
        return 0;
    }

    cout<<sum(cnt-1,cnt-1)<<endl;

    return 0;
}