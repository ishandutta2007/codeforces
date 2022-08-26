#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N, K, a, b, c, d;
    cin>>N>>K>>a>>b>>c>>d;
    if (K < N + 1 || N == 4)
    {
        cout<<-1<<endl;
        return 0;
    }
    set<int> Set;
    for(int i = 0; i < N; ++ i)
    {
        Set.insert(i + 1);
    }
    Set.erase(a);
    Set.erase(b);
    Set.erase(c);
    Set.erase(d);
    cout<<a<<' '<<c<<' ';
    for(auto elem:Set)
    {
        cout<<elem<<' ';
    }
    cout<<d<<' '<<b<<endl;
    cout<<c<<' '<<a<<' ';
    for(auto elem:Set)
    {
        cout<<elem<<' ';
    }
    cout<<b<<' '<<d<<endl;
}