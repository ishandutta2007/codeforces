#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

struct knight
{
    long long p,c,ind;
};

knight p[100001];
long long res[100001];
long long o[100001];

multiset<long long> Set;

bool cmp(knight a,knight b)
{
    return a.p<b.p;
}

int main ()
{
    long long n,k,i;
    multiset<long long> :: iterator it;

    cin>>n>>k;

    for(i=0;i<n;i++)
        cin>>p[i].p;
    for(i=0;i<n;i++)
        cin>>p[i].c;

    for(i=0;i<n;i++)
        p[i].ind=i;

    sort(p,p+n,cmp);

    for(i=0;i<n;i++)
    {
        if(!Set.empty())
            for(it=Set.begin();it!=Set.end();it++)
                res[i]+=*it;

        Set.insert(p[i].c);
        if(Set.size()>k)
        {
            it=Set.begin();
            Set.erase(it);
        }
    }

    for(i=0;i<n;i++)
        res[i]+=p[i].c;

    for(i=0;i<n;i++)
        o[p[i].ind]=res[i];

    for(i=0;i<n;i++)
        cout<<o[i]<<" ";

    cout<<endl;

    return 0;
}