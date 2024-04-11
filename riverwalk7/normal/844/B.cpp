#include <iostream>
#include <fstream>
#define MAXN 54
using namespace std;
int N, M;
int a[MAXN][MAXN];
typedef long long ll;
int c;
ll ans;
ll power(int x)
{
    if(x==0)
    {
        return 1;
    }
    else
    {
        return 2*power(x-1);
    }
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<N; i++)
    {
        c = 0;
        for(int j=0; j<M; j++)
        {
            c += a[i][j];
        }
        ans += power(c);
        ans += power(M-c);
        ans -= 2;
    }
    for(int i=0; i<M; i++)
    {
        c = 0;
        for(int j=0; j<N; j++)
        {
            c += a[j][i];
        }
        ans += power(c);
        ans += power(N-c);
        ans -= 2;
    }
    ans -= (M*N);
    cout<<ans<<endl;
}