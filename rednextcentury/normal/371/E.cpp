#include <bits/stdc++.h>
using namespace std;
struct station
{
    long long x;
    int id;
};
bool operator<(station a,station b)
{
    return a.x<b.x;
}
station a[1000000];
int main()
{
    int n,k;
    cin>>n;
    long long mn=0;
    for (int i=1;i<=n;i++) cin>>a[i].x,a[i].id=i;
    cin>>k;
    sort(a+1,a+n+1);
    long long sum=0,num=0,cur=0;
    long double best=-1;
    int ip;
    for (int i=1;i<=n;i++)
    {
        if (num<k)
        {
            cur+=a[i].x*num - sum;
            sum+=a[i].x;
            num++;
        }
        else
        {
            cur+=a[i].x*num - sum;
            sum-=a[i-k].x;
            sum+=a[i].x;
            cur-=sum;
            cur+=a[i-k].x*(num);
        }
        if (num==k)
        {
            if (cur<best || best==-1) best=cur,ip=i;
        }
    }
    for (int i=ip;i>=ip-k+1;i--)
        cout<<a[i].id<<" ";
    cout<<endl;
    return 0;
}