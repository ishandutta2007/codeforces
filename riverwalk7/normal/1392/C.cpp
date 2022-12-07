#include <iostream>
#include <fstream>
#define MAXN 200200
using namespace std;
typedef long long ll;
int pc, nc;
ll d[MAXN];
ll x[MAXN];
ll ans;
int T, N;
void update_pc()
{
    while(pc < N && d[pc] <= 0)
    {
        ++pc;
    }
}
void update_nc()
{
    while(nc < N && d[nc] >= 0)
    {
        ++nc;
    }
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        ans = 0;
        for(int j=0; j<N; j++)
        {
            cin>>x[j];
        }
        for(int j=0; j<N-1; j++)
        {
            d[j] = x[j+1]-x[j];
            if(d[j] < 0)
            {
                ans -= d[j];
            }
        }
        cout<<ans<<endl;
    }
}