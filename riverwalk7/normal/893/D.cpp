#include <iostream>
#include <fstream>
#define MAXN 100100
typedef long long ll;
using namespace std;
ll N, D;
ll a[MAXN];
ll prefix[MAXN];
ll cur;
ll best[MAXN];
ll ans;
int main()
{
    cin>>N>>D;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    best[N+1] = -1000000000000000000;
    for(int i=N; i>=1; i--)
    {
        best[i] = max(best[i+1], prefix[i]);
    }
    for(int i=1; i<=N; i++)
    {
        if((cur+prefix[i])>D)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(a[i]==0&&(cur+prefix[i])<0)
        {
            cur = D-best[i];
            ans++;
            if((cur + prefix[i]) < 0)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
}