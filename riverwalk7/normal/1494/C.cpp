#include <iostream>
#include <map>
#include <queue>
#define MAXN 200200
using namespace std;
int a[MAXN], b[MAXN];
int T;
void solve()
{
    int N, M;
    cin>>N>>M;
    map<int, bool> pos;
    queue<int> q;
    int countera = 0; int counterb = 0;
    int cnta = 0; int cntb = 0;
    int totp = 0; int totn = 0;
    int ctra = 0; int ctrb = 0;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        pos[a[i]] = true;
        if(a[i] < 0)
        {
            ++countera;
        }
    }
    for(int i=0; i<M; i++)
    {
        cin>>b[i];
        if(pos[b[i]])
        {
            if(b[i] > 0)
            {
                ++totp;
            }
            else
            {
                ++totn;
            }
        }
        if(b[i] < 0)
        {
            ++counterb;
        }
    }
    cnta = countera-1;
    int bestp = 0; int bestn = 0;
    for(int i=counterb; i<M; i++)
    {
        q.push(b[i]);
        ++totp;
        while(cnta < N-1 && a[cnta+1] <= b[i])
        {
            ++cnta;
            ++ctra;
            if(a[cnta] == b[i])
            {
                --totp;
            }
        }
        while(!q.empty() && q.front() + ctra <= b[i])
        {
            q.pop();
            --totp;
        }
        bestp = max(bestp, totp);
    }
    while(!q.empty())
    {
        q.pop();
    }
    cntb = countera;
    for(int i=counterb-1; i>=0; i--)
    {
        q.push(b[i]);
        ++totn;
        while(cntb > 0 && a[cntb-1] >= b[i])
        {
            --cntb;
            ++ctrb;
            if(a[cntb] == b[i])
            {
                --totn;
            }
        }
        if(!q.empty() && q.front() >= b[i] + ctrb)
        {
            q.pop();
            --totn;
        }
        bestn = max(bestn, totn);
    }
    cout<<bestp+bestn<<endl;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}