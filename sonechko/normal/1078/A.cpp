#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double

const int N = 1e6 + 11;

ld a,b,c;

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

ld get_x(ld y)
{
    return (-b*y-c)/a;
}

ld get_y(ld x)
{
    return (-a*x-c)/b;
}

ld min_dist(ld x, ld y, ld xx, ld yy)
{
    ld y2=get_y(x);
    ld ans=abs(y2-y)+dist(x,y2,xx,yy);
    ld x2=get_x(y);
    ans=min(ans,abs(x2-x)+dist(x2,y,xx,yy));
    x2=(ll)ceil(xx);
    y2=get_y(x2);
    ans=min(ans,abs(x2-x)+abs(y2-y)+dist(x2,y2,xx,yy));
    x2=(ll)floor(xx);
    y2=get_y(x2);
    ans=min(ans,abs(x2-x)+abs(y2-y)+dist(x2,y2,xx,yy));
    y2=(ll)ceil(yy);
    x2=get_x(y2);
    ans=min(ans,abs(x2-x)+abs(y2-y)+dist(x2,y2,xx,yy));
    y2=(ll)floor(yy);
    x2=get_x(y2);
    ans=min(ans,abs(x2-x)+abs(y2-y)+dist(x2,y2,xx,yy));
    return ans;
}

ld x1,y1,x2,y2;

ld min_dist_x(ld x)
{
    ld y=get_y(x);
    return min_dist(x1,y1,x,y)+min_dist(x2,y2,x,y);
}
ld min_dist_y(ld y)
{
    ld x=get_x(y);
    return min_dist(x1,y1,x,y)+min_dist(x2,y2,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(10);
    cin>>a>>b>>c;
    cin>>x1>>y1>>x2>>y2;
    ld ans=abs(x1-x2)+abs(y1-y2);
    if (a==0||b==0)
    {
        cout<<ans<<endl;
        return 0;
    }
    for (ll p=x1-10; p<=x1+10; p++)
        ans=min(ans,min_dist_x(p));
    for (ll p=x2-10; p<=x2+10; p++)
        ans=min(ans,min_dist_x(p));
    for (ll p=y1-10; p<=y1+10; p++)
        ans=min(ans,min_dist_y(p));
    for (ll p=y2-10; p<=y2+10; p++)
        ans=min(ans,min_dist_y(p));
    cout<<ans<<endl;
}