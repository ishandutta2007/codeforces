#include <iostream>
#include <fstream>
#define MAXN 110
using namespace std;
int N;
int a[MAXN];
int p[MAXN];
int q[MAXN];
int main()
{
    cin>>N;
    int ans = N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        p[i] = p[i-1] + a[i];
    }
    for(int i=N; i>=1; i--)
    {
        q[i] = q[i+1] + (!a[i]);
    }
    for(int i=0; i<=N; i++)
    {
        ans = min(ans, p[i] + q[i+1]);
    }
    cout<<N-ans<<endl;
}