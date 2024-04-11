#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int N;
int x, ans, m;
int a[MAXN];
int cur;
int main()
{
    ans = 1000000; m = 1000000007;
    cur = -1000000;
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        m = min(m, a[i]);
    }
    for(int i=1; i<=N; i++)
    {
        if(a[i]==m)
        {
            ans = min(ans, i-cur);
            cur = i;
        }
    }
    cout<<ans<<endl;
}