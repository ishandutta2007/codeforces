#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 100100
typedef long long ll;
using namespace std;
struct product
{
    ll k, l;
    product()
    {
        k = l = 0;
    }
    bool operator <(const product &rhs) const
    {
        return (min(2*k, l)-min(k, l)) > (min(2*rhs.k, rhs.l)-min(rhs.k, rhs.l));
    }
};
int N, K;
product a[MAXN];
ll ans;
int main()
{
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>a[i].k>>a[i].l;
    }
    sort(a, a+N);
    for(int i=0; i<N; i++)
    {
        if(i<K)
        {
            ans += min(2*a[i].k, a[i].l);
        }
        else
        {
            ans += min(a[i].k, a[i].l);
        }
    }
    cout<<ans<<endl;
}