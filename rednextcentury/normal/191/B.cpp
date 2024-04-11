#include <bits/stdc++.h>
using namespace std;
int a[1000000];
pair<int,int> b[1000000];
int ord[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    long long m;
    cin>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=make_pair(a[i],i);
    }
    sort(b+1,b+n,greater<pair<int,int> >());
    b[n].first = 0;
    long long sum=0;
    for (int i=1;i<n;i++)
    {
        if (i<k)sum+=b[i].first;
        ord[b[i].second]=i;
    }
    int num = k-1;
    for (int i=1;i<n;i++)
    {
        long long s = sum;
        if (ord[i]<=num)
        {
            s-=b[ord[i]].first;
            s+=b[k].first;
        }
        if (m-s < a[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}