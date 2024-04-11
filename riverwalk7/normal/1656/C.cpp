#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
int T, N;
int a[MAXN];
void solve()
{
    cin>>N;
    bool flag = false; //if there's a 1 or not
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        if(a[i] == 1)
        {
            flag = true;
        }
    }
    if(!flag)
    {
        cout<<"YES"<<endl;
        return;
    }
    sort(a, a+N);
    for(int i=1; i<N; i++)
    {
        if(a[i]-a[i-1] == 1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}