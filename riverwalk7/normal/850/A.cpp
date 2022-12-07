#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 34
using namespace std;
struct Point
{
    int a, b, c, d, e;
    Point()
    {
        a = b = c = d = e = 0;
    }
    Point(int aa, int bb, int cc, int dd, int ee)
    {
        a = aa; b = bb; c = cc; d = dd; e = ee;
    }
};
Point difference(Point s, Point t)
{
    return Point(s.a-t.a, s.b-t.b, s.c-t.c, s.d-t.d, s.e-t.e);
}
int dot(Point s, Point t)
{
    return (s.a*t.a+s.b*t.b+s.c*t.c+s.d*t.d+s.e*t.e);
}
Point x[MAXN];
vector<Point> v;
vector<int> ans;
bool flag;
int main()
{
    int N;
    cin>>N;
    if(N>=34)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1; i<=N; i++)
    {
        cin>>x[i].a>>x[i].b>>x[i].c>>x[i].d>>x[i].e;
    }
    for(int i=1; i<=N; i++)
    {
        v.clear();
        flag = true;
        for(int j=1; j<=N; j++)
        {
            if(j!=i)
            {
                v.push_back(difference(x[j], x[i]));
            }
        }
        for(int j=0; j<N-1; j++)
        {
            for(int k=0; k<N-1; k++)
            {
                if(k!=j&&dot(v[j], v[k])>0)
                {
                    flag = false;
                }
            }
        }
        if(flag)
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}