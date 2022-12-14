#include <bits/stdc++.h>
using namespace std;
set<pair<long long,int> > s;
long long a[1000000];
bool sign[1000000];
int main()
{
    int n,k;
    long long x;
    cin>>n>>k>>x;
    int mn=1000000000+2;
    int id=-1;
    int num=0;
    for (int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        if (a[i]<0)num++;
        if (abs(a[i])<mn)mn=abs(a[i]),id=i;
    }
    bool p=0;
    if (num%2==0)
    {
        if (a[id]>=0)
        {
            while(k && a[id]>=0)
            {
                a[id]-=x;
                k--;
            }
            p=(a[id]<0);
        }
        else
        {
            while(k && a[id]<=0)
            {
                a[id]+=x;
                k--;
            }
            p=(a[id]>0);
        }
    }
    for (int i=0;i<n;i++)
        s.insert(make_pair(abs(a[i]),i)),sign[i]=(a[i]<0);
    for (int i=0;i<k;i++)
    {
        pair<long long,int> p=*s.begin();
        s.erase(s.find(p));
        p.first+=x;
        s.insert(p);
    }
    for (int i=0;i<n;i++)
    {
         pair<long long,int> p=*s.begin();
         s.erase(s.find(p));
         a[p.second]=p.first;
    }
    for (int i=0;i<n;i++){
        if (sign[i])a[i]=-a[i];
        cout<<a[i]<<' ';
    }
    cout<<endl;
}