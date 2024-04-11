#include <iostream>
#include <vector>
#include <cstdio>
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
const int inf=~0U>>1;
using namespace std;
int N;
struct Point
{
    double x[3];
    Point()
    {
        x[0]=x[1]=x[2]=0;
    }
};
Point operator+(const Point a,const Point b)
{
    Point ret;
    rep(i,3)ret.x[i]=a.x[i]+b.x[i];
    return ret;
}
Point operator-(const Point a,const Point b)
{
    Point ret;
    rep(i,3)ret.x[i]=a.x[i]-b.x[i];
    return ret;
}
Point operator*(const Point a,double d)
{
    Point ret;
    rep(i,3)ret.x[i]=a.x[i]*d;
    return ret;
}
struct obj
{
    Point a;
    double w;
}P[110];
Point wcenter(vector<obj> objs)
{
    double wsum=0;
    rep(i,objs.size())
        wsum+=objs[i].w;
    Point a;
    rep(i,objs.size())
        a=a+objs[i].a*(objs[i].w/wsum);
    return a;
}
double x[100][2],y[100][2];
bool inrange(double x,double y,double a[2],double b[2])
{
    return x>=a[0]&&x<=a[1]&&y>=b[0]&&y<=b[1];
}
int main()
{
    //freopen("in","r",stdin);
    cin>>N;
    rep(i,N)
    {
        cin>>x[i][0]>>y[i][0]>>
            x[i][1]>>y[i][1];
        if(x[i][0]>x[i][1])
            swap(x[i][0],x[i][1]);
        if(y[i][0]>y[i][1])
            swap(y[i][0],y[i][1]);
    }
    double h=0;
    int ans=0;
    rep(i,N)
    {
        Point a;double side=x[i][1]-x[i][0];
        a.x[0]=x[i][0]+side/2;
        a.x[1]=y[i][0]+side/2;
        a.x[2]=h+side/2;
        h+=side;
        P[i].a=a;P[i].w=side*side*side;
        vector<obj>os;
        bool ok=true;
        for(int j=i;j>=1;j--)
        {
            os.pb(P[j]);
            Point c=wcenter(os);
            if(!inrange(c.x[0],c.x[1],x[j-1],y[j-1]))
            {
                ok=false;
                break;
            }
        }
        if(ok)ans=i+1;
        else break;
    }
    cout<<ans<<endl;
}