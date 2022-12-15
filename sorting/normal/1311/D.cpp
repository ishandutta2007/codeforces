#include <iostream>
#include <math.h>
 
using namespace std;
 
int a, b, c;
int na, nb, nc;
int res = 0;
 
void input()
{
    cin>>a>>b>>c;
}
 
void output()
{
    cout<<res<<'\n';
    cout<<na<<' '<<nb<<' '<<nc<<'\n';
}
 
void solve()
{
    res = -1;
    int ta, tb, tc;
    int tres = 0;
    for (tb = 1; tb<=20000; tb++)
    {
        if (abs(c-c/tb*tb) < abs(c-(c/tb+1)*tb)) tc = c/tb*tb;
        else tc = (c/tb+1)*tb;
 
        if (tb <= a) ta = tb;
        else
        {
            ta = 1;
            if (abs(tb-a) < abs(a-1)) ta = tb;
            for (int i=1; i*i <= tb; i++)
            {
                if (tb%i == 0)
                {
                    if (abs(a-i) < abs(ta-a)) ta = i;
                    if (abs(a-tb/i) < abs(ta-a)) ta = tb/i;
                }
            }
        }
        tres = abs(ta-a) + abs(tb-b) + abs(tc-c);
        //cout<<tres<<' '<<ta<<' '<<tb<<' '<<tc<<endl;
        if (tres < res || res == -1)
        {
            nc = tc;
            nb = tb;
            na = ta;
            res = tres;
        }
    }
}
 
void start()
{
    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        input();
        solve();
        output();
    }
 
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    start();
    return 0;
}