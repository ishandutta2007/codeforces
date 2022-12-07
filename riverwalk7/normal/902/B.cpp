#include <iostream>
#include <fstream>
#define MAXN 10010
using namespace std;
int N;
int p[MAXN];
int c[MAXN];
int ans;
int main()
{
    cin>>N;
    for(int i=2; i<=N; i++)
    {
        cin>>p[i];
    }
    for(int i=1; i<=N; i++)
    {
        cin>>c[i];
        if(c[i]!=c[p[i]])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}