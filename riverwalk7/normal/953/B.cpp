#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 100100
using namespace std;
int N;
int x[MAXN];
int s;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i];
    }
    sort(x, x+N);
    for(int i=0; i<N-1; i++)
    {
        s = __gcd(s, x[i+1]-x[i]);
    }
    cout<<(x[N-1]-x[0])/s+1-N;
}