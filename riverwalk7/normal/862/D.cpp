#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define MAXN 1010
using namespace std;
int N;
string a;
int K[16];
int u, v, length, mid;
int c; string f;
string flip(string x, int s, int t)
{
    for(int i=s; i<=t; i++)
    {
        x[i] = '0' + ('1' - x[i]);
    }
    return x;
}
void solve(int node, int l, int r, string g)
{
    cout<<"? "<<g<<endl;
    cin>>K[node];
    length = r-l+1;
    if(node > 0)
    {
        if((K[node]-K[node-1])==length)
        {
            if(g[l] == '1')
            {
                u = l;
            }
            else
            {
                v = l;
            }
        }
        if((K[node]-K[node-1])==-length)
        {
            if(g[l] == '1')
            {
                v = l;
            }
            else
            {
                u = l;
            }
        }
    }
    if(u==-1||v==-1)
    {
        if(abs(K[node]-K[node-1])==length)
        {
            c = min(N-1, length/2+r+1);
            solve(node+1, r+1, c, flip(g, r+1, c));
        }
        else
        {
            solve(node+1, l, (l+r)/2, flip(g, l, (l+r)/2));
        }
    }
}
int main()
{
    cin>>N;
    u = v = -1;
    for(int i=0; i<N; i++)
    {
        a = a + "0";
    }
    solve(0, 0, N-1, a);
    cout<<"!"<<" "<<u+1<<" "<<v+1<<endl;
}