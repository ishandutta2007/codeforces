#include <bits/stdc++.h>
using namespace std;
struct line
{
    long long k;
    long long b;
    void add(line x)
    {
        k+=x.k;
        b+=x.b;
    }
    void subtract(line x)
    {
        k-=x.k;
        b-=x.b;
    }
    bool isSame(line x)
    {
        return k==x.k && b==x.b;
    }
    line()
    {

    }
    line(long long K,long long B)
    {
        k=K;
        b=B;
    }
};
line a[1000000];
multiset<pair<long double, long long> > S;
bool is[1000000];
line tot;
int main()
{
    long long n;
    cin>>n;
    tot.b=0;
    tot.k=0;
    for (long long i=0;i<n;i++)
    {
        long long k,b;
        cin>>k>>b;
        a[i] = line(k,b);
        if (k==0 && b<0)
        {
            is[i]=1;
            tot.add(line(k,b));
        }
        else if (k!=0)
        {
            long double pos = (-1.0*b)/k;
            if (k<0)
            {
                is[i]=1;
                tot.add(line(k,b));
            }
            S.insert(make_pair(pos,i));
        }
    }
    line last = tot;
    long long num=1;
    while(S.size())
    {
        pair<long double,long long> p = *S.begin();
        S.erase(S.begin());
        if (is[p.second])
            tot.subtract(a[p.second]);
        else
            tot.add(a[p.second]);
        if (S.size() && abs((*S.begin()).first-p.first)<1e-20)
            continue;
        if (!tot.isSame(last))
            num++;
        last  = tot;
    }
    cout<<num-1<<endl;
}