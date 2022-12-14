#include <bits/stdc++.h>
using namespace std;
set<long long> S,E;
long long speed=0;
long long Stairs(int x1,int y1,int x2,int y2)
{
    auto it = S.upper_bound(y1);
    long long c1=1e18,c2=1e18;
    if (it!=S.end())
    {
        long long y = *it;
        c1 = abs(y1-y)+abs(y-y2)+abs(x1-x2);
    }
    if (it!=S.begin())
    {
        it--;
        long long y = *it;
        c2 = abs(y1-y)+abs(y-y2)+abs(x1-x2);
    }
    return min(c1,c2);
}
long long Elevators(int x1,int y1,int x2,int y2)
{
    auto it = E.upper_bound(y1);
    long long c1=1e18,c2=1e18;
    if (it!=E.end())
    {
        long long y = *it;
        c1 = abs(y1-y)+abs(y-y2)+(abs(x1-x2)/speed)+((abs(x1-x2)%speed)>0);
    }
    if (it!=E.begin())
    {
        it--;
        long long y = *it;
        c2 = abs(y1-y)+abs(y-y2)+(abs(x1-x2)/speed)+((abs(x1-x2)%speed)>0);
    }
    return min(c1,c2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,stairs,elevators;
    cin>>n>>m>>stairs>>elevators>>speed;
    for (int i=0;i<stairs;i++)
    {
        int x;
        cin>>x;
        S.insert(x);
    }
    for (int i=0;i<elevators;i++)
    {
        int x;
        cin>>x;
        E.insert(x);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2)
        {
            cout<<abs(y1-y2)<<endl;
        }
        else
        {
            cout<<min(Stairs(x1,y1,x2,y2),Elevators(x1,y1,x2,y2))<<endl;
        }
    }
}