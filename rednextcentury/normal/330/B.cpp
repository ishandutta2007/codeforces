#include<iostream>
# include <queue>
#include <vector>
using namespace std;
bool v[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a]=v[b]=1;
    }
    cout<<n-1<<endl;
    for (int i=1;i<=n;i++)
    {
        if (!v[i])
        {
            for (int x=1;x<=n;x++)
            {
                if (i==x)
                    continue;
                cout<<i<<" "<<x<<endl;
            }
            return 0;
        }
    }
}