#include <iostream>
#define MAXN 1010
using namespace std;
int N, M;
int a[MAXN];
int x, y, sum;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    cin>>M;
    for(int i=0; i<M; i++)
    {
        cin>>x>>y;
        if(y >= sum)
        {
            cout<<max(x, sum)<<endl; return 0;
        }
    }
    cout<<-1<<endl;
}