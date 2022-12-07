#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
int N, D;
int P[MAXN];
int tot, ans;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    cin>>N>>D;
    for(int i=0; i<N; i++)
    {
        cin>>P[i];
    }
    sort(P, P+N, comp);
    for(int i=0; i<N; i++)
    {
        tot += (D/P[i] + 1);
        if(tot <= N)
        {
            ans += 1;
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
}