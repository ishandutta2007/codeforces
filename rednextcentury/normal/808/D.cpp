#include<bits/stdc++.h>

using namespace std;
long long a[1000000];
map<long long,long long> pre;
map<long long,long long> suf;
int main()
{
    ios_base::sync_with_stdio(0);
    long long n;
    cin>>n;
    long long sum=0;
    for (int i=0;i<n;i++)
        cin>>a[i],sum+=a[i],suf[a[i]]++;
    long long l=0,r=sum;
    bool ok=0;
    for (int i=0;i<n;i++)
    {
        l+=a[i],r-=a[i];
        pre[a[i]]++,suf[a[i]]--;
        if (l==r)
            ok=1;
        else if (l>r)
        {
            if ((l-r)%2==0 && pre[(l-r)/2]>0)
                ok=1;
        }
        else if ((r-l)%2==0 && suf[(r-l)/2]>0)
            ok=1;
    }
    if (ok && n>1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}