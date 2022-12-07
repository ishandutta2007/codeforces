#include <iostream>
#include <fstream>
#define MAXN 7070
using namespace std;
typedef long long ll;
ll a[MAXN];
ll w[MAXN];
int deg[MAXN];
int N;
ll ans;
int counter;
bool flag;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N; i++)
    {
        cin>>w[i];
        ans += w[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if((a[i] & a[j]) != a[i])
            {
                ++deg[i];
            }
        }
    }
    counter = N-1;
    while(true)
    {
        flag = false;
        for(int i=0; i<N; i++)
        {
            if(deg[i] == counter)
            {
                ans -= w[i];
                for(int j=0; j<N; j++)
                {
                    if((a[j] & a[i]) != a[j])
                    {
                        --deg[j];
                    }
                }
                --counter;
                flag = true;
                break;
            }
        }
        if(!flag) break;
    }
    cout<<ans<<endl;
}