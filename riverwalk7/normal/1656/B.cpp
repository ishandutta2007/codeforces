#include <bits/stdc++.h>
#define MAXN 200200
using namespace std;
int T;
int a[MAXN];
int N, K;
map<int, bool> m;
void solve()
{
    cin>>N>>K;
    m.clear();
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        m[a[i]] = true;
    }
    for(int i=0; i<N; i++)
    {
        if(m[a[i] + K])
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}