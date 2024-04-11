#include <iostream>

using namespace std;

struct k
{
    int x,y,r,R;
};

bool inter(int x1,int y1, int r1, int x2,int y2, int r2)
{
    int d  = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return (d>=(r1+r2)*(r1+r2))||(d<((r1+r2)*(r1+r2))&&d<=((r1-r2)*(r1-r2)));
}

int main()
{
    k a[2];
    for (int i=0;i<2;i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].r >> a[i].R;
    }
    int ans=0;
    for (int i=0;i<2;i++)
    {
        bool T=true;
        for (int j=a[i^1].r;j<=a[i^1].R;j++) T&=inter(a[i].x,a[i].y,a[i].r,a[i^1].x,a[i^1].y,j);
        ans+=T;
        T=true;
        for (int j=a[i^1].r;j<=a[i^1].R;j++) T&=inter(a[i].x,a[i].y,a[i].R,a[i^1].x,a[i^1].y,j);
        ans+=T;
    }
    cout << ans;
    return 0;
}