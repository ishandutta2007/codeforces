#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 300100
using namespace std;
int N, M;
vector<char> c[MAXN]; char d;
vector<char> g[MAXN];
vector<char> h[MAXN];
char a[4];
int ans;
void solve1(int x, int y)
{
    int total = 0; int total1 = 0; int total2 = 0; int c2, c1;
    for(int j=0; j<M; j++)
    {
        total1 = total2 = 0;
        if(j > 0)
        {
            c2 = c1 = 0;
            for(int i=0; i<4; i++)
            {
                if(a[i] != g[0][j-1] && a[i] != g[1][j-1])
                {
                    if(!c2)
                    {
                        c2 = i;
                    }
                    else
                    {
                        c1 = i;
                    }
                }
            }
        }
        else
        {
            c1 = x; c2 = y;
        }
        g[0][j] = a[c2]; if(g[0][j] != c[0][j]) ++total1;
        g[1][j] = a[c1]; if(g[1][j] != c[1][j]) ++total1;
        for(int i=2; i<N; i++)
        {
            g[i][j] = g[i-2][j];
            if(g[i][j] != c[i][j])
            {
                ++total1;
            }
        }
        g[0][j] = a[c1];
        g[1][j] = a[c2];
        if(g[0][j]!= c[0][j]) ++total2;
        if(g[1][j]!= c[1][j]) ++total2;
        for(int i=2; i<N; i++)
        {
            g[i][j] = g[i-2][j];
            if(g[i][j] != c[i][j])
            {
                ++total2;
            }
        }
        total += min(total1, total2);
        if(total1 < total2)
        {
            for(int i=0; i<N; i++)
            {
                if(i%2==0)
                {
                    g[i][j] = a[c2];
                }
                else
                {
                    g[i][j] = a[c1];
                }
            }
        }
    }
    if(total < ans)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                h[i][j] = g[i][j];
            }
        }
        ans = total;
    }
}
void solve(int x, int y)
{
    int total = 0; int total1 = 0; int total2 = 0; int c2, c1;
    for(int i=0; i<N; i++)
    {
        total1 = total2 = 0;
        if(i > 0)
        {
            c2 = c1 = 0;
            for(int j=0; j<4; j++)
            {
                if(a[j] != g[i-1][0] && a[j] != g[i-1][1])
                {
                    if(!c2)
                    {
                        c2 = j;
                    }
                    else
                    {
                        c1 = j;
                    }
                }
            }
        }
        else
        {
            c1 = x; c2 = y;
        }
        g[i][0] = a[c2]; if(g[i][0] != c[i][0]) ++total1;
        g[i][1] = a[c1]; if(g[i][1] != c[i][1]) ++total1;
        for(int j=2; j<M; j++)
        {
            g[i][j] = g[i][j-2];
            if(g[i][j] != c[i][j])
            {
                ++total1;
            }
        }
        g[i][0] = a[c1];
        g[i][1] = a[c2];
        if(g[i][0]!= c[i][0]) ++total2;
        if(g[i][1]!= c[i][1]) ++total2;
        for(int j=2; j<M; j++)
        {
            g[i][j] = g[i][j-2];
            if(g[i][j] != c[i][j])
            {
                ++total2;
            }
        }
        total += min(total1, total2);
        if(total1 < total2)
        {
            for(int j=0; j<M; j++)
            {
                if(j%2==0)
                {
                    g[i][j] = a[c2];
                }
                else
                {
                    g[i][j] = a[c1];
                }
            }
        }
    }
    if(total < ans)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                h[i][j] = g[i][j];
            }
        }
        ans = total;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    a[0] = 'A'; a[1] = 'G'; a[2] = 'C'; a[3] = 'T'; ans = 1234567;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>d;
            c[i].push_back(d);
            g[i].push_back(d);
            h[i].push_back(d);
        }
    }
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            g[0][0] = a[i]; g[0][1] = a[j];
            if(a[i] != a[j])
            {
                solve(i, j);
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            g[0][0] = a[i]; g[1][0] = a[j];
            if(a[i] != a[j])
            {
                solve1(i, j);
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout<<h[i][j];
        }
        cout<<""<<endl;
    }
}