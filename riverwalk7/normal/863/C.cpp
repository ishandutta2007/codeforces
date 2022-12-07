#include <iostream>
#include <fstream>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll K, cycle, t;
pii start;
map<pii, int> m;
map<pii, pii> s;
map<pii, ll> frequency;
ll a, b;
ll outcome(int u, int v)
{
    if(u%3==(v+1)%3)
    {
        return 1;
    }
    else if((u+1)%3==v%3)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin>>K>>start.first>>start.second;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cin>>s[make_pair(i, j)].first;
        }
    }
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cin>>s[make_pair(i, j)].second;
        }
    }
    for(int i=1; i<=K; i++)
    {
        frequency[start]++;
        if(m[start] == 0)
        {
            m[start] = i;
            start = s[start];
        }
        else
        {
            cycle = i-m[start];
            start = s[start];
            t = K-i;
            break;
        }
    }
    for(int i=0; i<cycle; i++)
    {
        frequency[start] += ((t+cycle-1-i)/cycle);
        start = s[start];
    }
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            if(outcome(i, j) == 1)
            {
                a+= frequency[make_pair(i, j)];
            }
            if(outcome(i, j) == -1)
            {
                b+= frequency[make_pair(i, j)];
            }
        }
    }
    cout<<a<<" "<<b<<endl;
}