#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int level[MAXN];
int cnt[MAXN];
int N, p, ans;
int main()
{
    cin>>N;
    cnt[0] = 1;
    for(int i=2; i<=N; i++)
    {
        cin>>p;
        level[i] = level[p]+1;
        cnt[level[i]]++;
    }
    for(int i=0; i<N; i++)
    {
        if(cnt[i]%2==1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}