#include <bits/stdc++.h>
using namespace std;
set<int> s;
void Rem(int x)
{
    vector<int>primes;
    for (int i=2;i*i<=x;i++)
    {
        if (x%i==0)
            primes.push_back(i);
        while(x%i==0)
            x/=i;
    }
    if (x)primes.push_back(x);
    for (int i=0;i<primes.size();i++)
    {
        int j=primes[i];
        if (s.find(j)==s.end())
            continue;
        while(j<=2000000)
        {
            if (s.find(j)!=s.end())
                s.erase(j);
            j+=primes[i];
        }
    }
}
int a[1000000];
int b[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=2;i<=2000000;i++)
        s.insert(i);
    int i=0;
    while(i<n)
    {
        if (s.find(a[i])!=s.end())
        {
            Rem(a[i]);
            b[i]=a[i];
            i++;
        }
        else
            break;
    }
    if (i<n){
        b[i] = *s.upper_bound(a[i]);
        Rem(b[i]);
        i++;
    }
    while(i<n)
    {
        if (s.size()==0)
            assert(0);
        b[i]=*s.begin();
        Rem(b[i]);
        i++;
    }
    for (int i=0;i<n;i++)
        cout<<b[i]<<' ';
}