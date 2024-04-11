#include <iostream>
#include <fstream>
#include <string>
#define MAXN 300300
#define MAXS 500500
using namespace std;
string s;
int N;
int x[MAXN]; int y[MAXN];
int ux, uy, dx, dy, cx, cy;
int uk, dk;
int cur, ans;
int judge(int a, int b)
{
    return max(max(uy-b, b-dy), max(uk-(b-a), (b-a)-dk));
}
int main()
{
    cin>>N;
    ux = -MAXS;
    dx = MAXS;
    uy = -MAXS;
    dy = MAXS;
    uk = -MAXS;
    dk = MAXS;
    for(int i=0; i<N; i++)
    {
        cin>>s;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == 'B')
            {
                ++x[i];
            }
            else
            {
                ++y[i];
            }
        }
        ux = max(ux, x[i]);
        dx = min(dx, x[i]);
        uy = max(uy, y[i]);
        dy = min(dy, y[i]);
        uk = max(uk, y[i]-x[i]);
        dk = min(dk, y[i]-x[i]);
    }
    ans = MAXS;
    for(int i=0; i<MAXS; i++)
    {
        cur = max(ux-i, i-dx);
        int lbound = 0; int hbound = MAXS; int avg;
        if(i == 0) lbound = 1;
        while(lbound != hbound)
        {
            avg = (lbound + hbound)/2;
            if(judge(i, avg) < judge(i, avg+1))
            {
                hbound = avg;
            }
            else
            {
                lbound = avg+1;
            }
        }
        while(judge(i, avg+1) < judge(i, avg))
        {
            ++avg;
        }
        while(judge(i, avg-1) < judge(i, avg) && avg > 0 && avg+i > 1)
        {
            --avg;
        }
        if(max(cur, judge(i, avg)) < ans)
        {
            ans = max(cur, judge(i, avg));
            cx = i; cy = avg;
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<cx; i++)
    {
        cout<<"B";
    }
    for(int i=0; i<cy; i++)
    {
        cout<<"N";
    }
    cout<<""<<endl;
}