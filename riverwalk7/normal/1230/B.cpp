#include <iostream>
#include <fstream>
#define MAXN 200200
using namespace std;
int N, K;
char b[MAXN];
int a[MAXN];
int main()
{
    cin>>N>>K;
    if(N == 1 && K > 0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0; i<N; i++)
    {
        cin>>b[i];
        a[i] = b[i]-'0';
        if(K && i == 0 && a[i] > 1)
        {
            a[i] = 1; --K;
        }
        else if(K && i != 0 && a[i] != 0)
        {
            a[i] = 0; --K;
        }
    }
    for(int i=0; i<N; i++)
    {
        cout<<a[i];
    }
}