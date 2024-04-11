#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
string s;
int a[6];
int b[6];
bool comp(int a, int b)
{
    return a>b;
}
int main()
{
    cin>>s;
    for(int i=0; i<6; i++)
    {
        a[i] = s[i] - '0';
    }
    if((a[0]+a[1]+a[2])>(a[3]+a[4]+a[5]))
    {
        for(int i=0; i<3; i++)
        {
            swap(a[i], a[i+3]);
        }
    }
    for(int i=0; i<3; i++)
    {
        b[i] = 9-a[i];
        b[i+3]=a[i+3];
    }
    sort(b, b+6, comp);
    int potential = a[3]+a[4]+a[5]-a[0]-a[1]-a[2];
    for(int i=0; i<6; i++)
    {
        if(potential <= 0)
        {
            cout<<i<<endl;
            return 0;
        }
        potential -= b[i];
    }
}