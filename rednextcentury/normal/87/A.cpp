# include<iostream>
# include<set>
#include <map>
# include <algorithm>
using namespace std;
long long times[10000000];
map<long long,long long> mp;
int main()
{
    string m,d;
    m="Masha",d="Dasha";
    long long a,b;
    cin>>a>>b;
    long long k=a*b;
    if (a>b)
    {
        swap(a,b);
        swap(m,d);
    }
    long long iii=b;
    long long tot=0;
    times[tot++]=0;
    while(iii<=k)
    {
        times[tot++]=iii;
        mp[iii]++;
        iii+=b;
    }
    iii=a;
    while(iii<=k)
    {
        if (mp[iii]==0)
            times[tot++]=iii;
        iii+=a;
    }
    long long d1=0,m1=0;
    sort(times,times+tot);
    for (long long i=1;i<tot;i++)
    {
        if (times[i]%b==0)
        {
           m1+=times[i]-times[i-1];
        }
        else
            d1+=times[i]-times[i-1];
    }
    if (m1>d1)
        cout<<m<<endl;
    else if (m1<d1)
        cout<<d<<endl;
    else
        cout<<"Equal"<<endl;
}