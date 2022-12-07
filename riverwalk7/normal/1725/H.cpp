#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
int N;
int x[3];
int a[MAXN];
bool b[MAXN];
int good(int s, int t)
{
    bool c[] = {true, true, true};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(((1 << i) & s) && ((1<<j) & t))
            {
                c[(i*i+j*j) % 3] = false;
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        if(c[i] == true)
        {
            return i;
        }
    }
    return -1;
}
bool possible(int s, int t)
{
    int l = 0;
    int r = 0;
    for(int i=0; i<3; i++)
    {
        if(((1 << i) & s) && !((1<<i) & t))
        {
            l += x[i];
        }
        if(!((1<<i) & s) && ((1<<i) & t))
        {
            r += x[i];
        }
        if(!((1<<i) & s) && !((1<<i) & t))
        {
            if(x[i] != 0)
            {
                return false;
            }
        }
    }
    if(l > N/2 || r > N/2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void assign_stones(int s, int t)
{
    cout<<good(s, t)<<endl;
    bool v[3];
    bool w[3];
    int cv = N/2;
    int cw = N/2;
    for(int i=0; i<3; i++)
    {
        v[i] = s & (1<<i);
        w[i] = t & (1<<i);
    }
    for(int i=0; i<N; i++)
    {
        if(v[a[i] % 3] && !w[a[i] % 3])
        {
            b[i] = false;
            cv -= 1;
        }
        if(!v[a[i] % 3] && w[a[i] % 3])
        {
            b[i] = true;
            cw -= 1;
        }
    }
    for(int i=0; i<N; i++)
    {
        if(v[a[i] % 3] && w[a[i] % 3])
        {
            if(cv > 0)
            {
                b[i] = false;
                cv -= 1;
            }
            else
            {
                b[i] = true;
                cw -= 1;
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        if(b[i] == false)
        {
            cout<<0;
        }
        if(b[i] == true)
        {
            cout<<1;
        }
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        x[a[i] % 3]++;
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(good(i, j) != -1)
            {
                if(possible(i, j))
                {
                    assign_stones(i, j);
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
}