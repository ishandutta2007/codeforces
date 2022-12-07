#include <iostream>
#include <fstream>
#define MAXN 2020
using namespace std;
int N, d, b, s, cur, ans;
int a[MAXN];
int prefix[MAXN];
int prefix2[MAXN];
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        prefix[i] = prefix[i-1] + (a[i]==1);
    }
    for(int i=N; i>=1; i--)
    {
        prefix2[i] = prefix2[i+1] + (a[i]==2);
    }
    for(int i=1; i<=N; i++)
    {
        b = d = 0; s = i-1;
        cur = 0;
        for(int j=i; j<=N; j++)
        {
            if(a[j]==2)
            {
                d += 1;
            }
            else
            {
                d -= 1;
            }
            b = max(b, d);
            cur = prefix[j]-prefix[i-1]+b;
            ans = max(ans, prefix[i-1]+prefix2[j+1]+cur);
        }
    }
    cout<<ans<<endl;
}