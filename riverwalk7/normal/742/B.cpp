#include <iostream>
#include <map>
#define MAXN 134100
using namespace std;
typedef long long ll;
int a[MAXN];
ll m[MAXN];
ll ans;
int main()
{
    int N, X; cin>>N>>X;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    for(int i=0; i<N; i++)
    {
        ans += m[a[i] ^ X];
    }
    if(X!=0)
    cout<<ans/2<<endl;
    else
    {
        cout<<ans/2-N/2<<endl;
    }
}