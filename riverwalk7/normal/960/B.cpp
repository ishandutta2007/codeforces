#include <iostream>
#include <fstream>
#include <cmath>
#define MAXN 1010
using namespace std;
typedef long long ll;
int N, k1, k2;
ll a[MAXN];
ll b[MAXN];
ll ans;
ll best1, best2;
int main()
{
    cin>>N>>k1>>k2;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N; i++)
    {
        cin>>b[i];
        ans += ((a[i]-b[i])*(a[i]-b[i]));
    }
    for(int i=0; i<k1+k2; i++)
    {
        best1 = -100;
        for(int j=0; j<N; j++)
        {
            if(best1 < 2*abs(a[j]-b[j])-1)
            {
                best2 = j;
            }
            best1 = max(best1, 2LL*ll(abs(a[j]-b[j]))-1LL);
        }
        ans -= best1;
        if(a[best2] > b[best2])
        {
            a[best2]--;
        }
        else
        {
            b[best2]--;
        }
    }
    cout<<ans<<endl;
}