#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
    int N, d, h;
    cin>>N>>d>>h;
    if (d >= N)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (d < h)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (d == 1)
    {
        if (N > 2)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if (d - h > h)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 1; i <= h; ++ i)
    {
        cout<<i<<' '<<i+1<<endl;
    }
    for(int i = h + 1; i <= d; ++i)
    {
        if (i == h + 1)
        {
            cout<<1<<' '<<i+1<<endl;
        }
        else
        {
            cout<<i<<' '<<i+1<<endl;
        }
    }
    for(int i = d + 1; i < N; ++ i)
    {
        cout<<h<<' '<<i + 1<<endl;
    }
}