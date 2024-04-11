# include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int op[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    multiset<pair<long long,int> > s;
    long long ret=0;
    long long sum=0;
    for (int i=1;i<=k+n;i++)
    {
        if (i<=n)s.insert(make_pair(a[i],i)),sum+=a[i];
        if (i>k)
        {
            pair<long long,int> p=*(--s.end());
            sum-=p.first;
            op[p.second]=i;
            s.erase(--s.end());
        }
        ret+=sum;
    }
    cout<<ret<<endl;
    for (int i=1;i<=n;i++)
        cout<<op[i]<<' ';
    cout<<endl;
}