#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#define MAXN 100100
using namespace std;
typedef long long ll;
ll x[MAXN], y[MAXN];
int N;
void solve()
{
    cin>>N;
    ll a, b;
    double ans = 0;
    int counterx = 0; int countery = 0;
    for(int i=0; i<2*N; i++)
    {
        cin>>a>>b;
        if(a == 0)
        {
            y[countery] = abs(b);
            ++countery;
        }
        else
        {
            x[counterx] = abs(a);
            ++counterx;
        }
    }
    sort(x, x+N);
    sort(y, y+N);
    for(int i=0; i<N; i++)
    {
        ans += sqrt(x[i]*x[i]+y[i]*y[i]);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}