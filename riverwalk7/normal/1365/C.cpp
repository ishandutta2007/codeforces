#include <iostream>
#include <fstream>
#define MAXN 200100
using namespace std;
int N;
int a[MAXN], b[MAXN];
int q[MAXN], r[MAXN];
int s[MAXN];
int ans;
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        q[a[i]] = i;
    }
    for(int i=1; i<=N; i++)
    {
        cin>>b[i];
        r[b[i]] = i;
    }
    for(int i=1; i<=N; i++)
    {
        s[(r[i]-q[i]+N)%N]++;
    }
    for(int i=0; i<N; i++)
    {
        ans = max(ans, s[i]);
    }
    cout<<ans<<endl;
}