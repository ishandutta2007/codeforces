#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100
using namespace std;
typedef long long ll;
ll P, K;
ll a[MAXN];
ll d, c;
int main()
{
    cin>>P>>K;
    while(P > 0)
    {
        a[c] = P%K;
        P /= K;
        ++c;
    }
    for(int i=0; i<100; i++)
    {
        while(a[i] > 0&&i%2==1)
        {
            a[i] -= K;
            a[i+1] += 1;
        }
        if(i%2==1)
        {
            a[i] = -a[i];
        }
        while(a[i]>=K)
        {
            a[i] -= K;
            a[i+1] += 1;
        }
    }
    for(int i=99; i>=0; i--)
    {
        if(a[i] != 0)
        {
            d = i+1;
            cout<<i+1<<endl;
            break;
        }
    }
    for(int i=0; i<d-1; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[d-1]<<endl;
}