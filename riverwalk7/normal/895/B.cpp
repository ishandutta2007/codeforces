#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
map<int, int> n;
int N, X, K;
long long a[100100], ans, c, d;
int main()
{
    cin>>N>>X>>K;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        c = (a[i]-1)/X;
        if(K!=0||a[i]%X!=0)
        m[c]++;
    }
    for(int i=0; i<N; i++)
    {
        d = a[i]/X;
        ans += m[d-K];
    }
    if(K!=0)
    {
        cout<<ans<<endl;
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            if(a[i]%X!=0)
                n[a[i]]++;
        }
        for(int i=0; i<N; i++)
        {
            ans += n[a[i]];
        }
        ans/=2;
        cout<<ans<<endl;
    }
}