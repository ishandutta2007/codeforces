#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 2205
using namespace std;
int K, N;
int a[MAXN];
int ans;
int main()
{
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    sort(a, a+N);
    for(int i=0; i<K; i++)
    {
        ans += a[i];
    }
    cout<<ans<<endl;
}