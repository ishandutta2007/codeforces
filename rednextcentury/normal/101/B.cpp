# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
#include <set>
#include <map>
#define MOD 1000000007
using namespace std;
map<long long,long long> mp;
set<long long> st;
struct range
{
    long long s;
    long long e;
};
range r[1000000];
long long first[1000000];
long long sum[1000000];
long long check[1000000];
long long l[1000000];
bool comp(range a,range b)
{
    return a.e<b.e;
}
long long ans[1000000];
int main()
{
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    long long mx=0,mn=1000000001;
    for (long long i=1;i<=m;i++)
    {
        cin>>r[i].s>>r[i].e;
        mn=min(mn,r[i].s);
        mx=max(mx,r[i].e);
        st.insert(r[i].s);
        st.insert(r[i].e);
    }
    if (mn!=0 || mx!=n)
    {
        cout<<0<<endl;
        return 0;
    }
    long long h=1;
    for (set<long long>::iterator it=st.begin();it!=st.end();it++)
    {
        mp[*it]=h;
        h++;
    }
    r[0].s=r[0].e=1;
    for (long long i=1;i<=m;i++)
    {
        r[i].s=mp[r[i].s];
        r[i].e=mp[r[i].e];
        check[r[i].s]++;
        check[r[i].e+1]--;
        sum[r[i].e]++;
    }
    bool p=1;
    for (long long i=1;i<h;i++)
    {
        check[i]+=check[i-1];
        if (check[i]==0)
            p=0;
    }
    if (p==0)
    {
        cout<<0<<endl;
        return 0;
    }
    sum[1]=1;
    ans[0]=1;
    for (long long i=1;i<=h;i++)
    {
        sum[i]+=sum[i-1];
    }
    sort(r,r+m+1,comp);
   
    for (long long i=1;i<=m;i++)
    {

        if (r[first[r[i].e]].e!=r[i].e)
            first[r[i].e]=i;
    }
    l[0]=1;
    for (long long i=1;i<=m;i++)
    {
        long long num=sum[r[i].e-1]-sum[r[i].s-1];
        ans[i]=(l[first[r[i].e]-1]+MOD-l[first[r[i].e]-1-num])%MOD;
        l[i]=(l[i-1]+ans[i])%MOD;
        l[i]%=MOD;
    }
    cout<<(l[m]+MOD-l[first[h-1]-1])%MOD<<endl;
}