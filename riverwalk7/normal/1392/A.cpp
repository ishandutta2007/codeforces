#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 200200
using namespace std;
int T, N;
int a[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>a[j];
        }
        sort(a, a+N);
        if(a[0] != a[N-1])
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<N<<endl;
        }
    }
}