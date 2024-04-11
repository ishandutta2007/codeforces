# include<iostream>
# include<iomanip>
#include <ios>
# include <algorithm>
using namespace std;
struct batata
{
    long long essays;
    long long mark;
};
batata a[100001];
bool comp(batata a,batata b)
{
    return a.essays<b.essays;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,r,avg;
    cin>>n>>r>>avg;
    long long sum=0;
    for (long long i=0;i<n;i++)
    {
        cin>>a[i].mark;
        cin>>a[i].essays;
        sum+=a[i].mark;
    }
    sort(a,a+n,comp);
    long long i=0;
    long long ans=0;
    while(sum<n*avg)
    {
        long long need=n*avg-sum;
        long long can=min(r,a[i].mark+need);
        ans+=a[i].essays*(can-a[i].mark);
        sum+=can-a[i].mark;
        i++;;
    }
    cout<<ans<<endl;
}