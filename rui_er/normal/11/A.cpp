#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    int k[a];
    for(int i=0;i<a;i++) cin>>k[i];
    int cnt = 0;
    for(int i=1;i<a;i++)
    {
        if(k[i-1] >= k[i])
        {
            int l = (k[i-1] - k[i]) / b + 1;
            cnt += l;
            k[i] += b * l;
        }
    }
    cout<<cnt<<endl;
    return 0;
}