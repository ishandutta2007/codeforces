# include <iostream>
# include <algorithm>
using namespace std;
long long x[10];
long long y[10];
long long distance(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool check()
{
    long long  dist[10];
    dist[0]=distance(x[0],y[0],x[1],y[1]);
    dist[1]=distance(x[0],y[0],x[2],y[2]);
    dist[2]=distance(x[1],y[1],x[2],y[2]);
    sort(dist,dist+3);
    if (dist[0]+dist[1]==dist[2] && dist[0]!=0)
        return 1;
    return 0;
}
int main()
{
    for (int i=0;i<3;i++) cin>>x[i]>>y[i];
    if (check())
        cout<<"RIGHT"<<endl;
    else
    {
        bool p=0;
        for (int i=0;i<3;i++)
        {
            x[i]++;
            if (check())
                p=1;
            x[i]-=2;
            if (check())
                p=1;
            x[i]++;
            y[i]++;
            if (check())
                p=1;
            y[i]-=2;
            if (check())
                p=1;
            y[i]++;
        }
        if (p) cout<<"ALMOST"<<endl;
        else
        cout<<"NEITHER"<<endl;
    }
}