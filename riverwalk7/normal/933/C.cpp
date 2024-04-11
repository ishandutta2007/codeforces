#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int N;
int x[3], y[3], r[3], t, u, v, w;
int s[3], ans;
bool flag;
int intersect(int a, int b)
{
    v = (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
    u = (r[a]+r[b])*(r[a]+r[b]);
    w = (r[a]-r[b])*(r[a]-r[b]);
    if(v<u&&v>w)
    {
        return 2;
    }
    if(v==u||w==v)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    for(int i=0; i<3; i++)
    {
        x[i] *= 100; y[i]*=100; r[i]*=100;
    }
    for(int i=-2000; i<=2000; i++)
    {
        for(int j=-2000; j<=2000; j++)
        {
            flag = true;
            for(int k=0; k<3; k++)
            {
                if(abs((i-x[k])*(i-x[k])+(j-y[k])*(j-y[k])-r[k]*r[k])>1)
                {
                    flag = false;
                }
            }
            if(flag)
            {
                ans--;
            }
        }
    }
    return;
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i]>>y[i]>>r[i];
    }
    if(N==1)
    {
        cout<<2<<endl;
        return 0;
    }
    if(N==2)
    {
        if(intersect(0, 1)==2)
        {
            cout<<4<<endl;
        }
        else
        {
            cout<<3<<endl;
        }
        return 0;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            s[i] += intersect(i, j);
            s[j] += intersect(i, j);
            t += intersect(i, j);
        }
    }
    for(int i=0; i<3; i++)
    {
        s[i] = max(1, s[i]);
        ans += s[i];
    }
    ans -= max(t, 1); ans += 2;
    solve();
    cout<<max(ans, 4)<<endl;
}