#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#define MAXN 1000100
using namespace std;
string s;
int p[MAXN], q[MAXN]; //pointer to next element
int c[MAXN];
bool g[MAXN];
queue<int> r;
int ans;
int v;
vector<int> t;
bool update(int x)
{
    if(p[x]!=-1&&c[x]!=c[p[x]])
    {
        return true;
    }
    if(q[x]!=-1&&c[x]!=c[q[x]])
    {
        return true;
    }
    return false;
}
void update2(int x)
{
    if(p[x]!=-1)
    {
        q[p[x]] = q[x];
        t.push_back(p[x]);
    }
    if(q[x]!=-1)
    {
        p[q[x]] = p[x];
        t.push_back(q[x]);
    }
    return;
}
int main()
{
    cin>>s;
    for(int i=0; i<s.length()-1; i++)
    {
        q[i+1] = i;
        p[i] = i+1;
    }
    p[s.length()-1] = -1;
    q[0] = -1;
    for(int i=0; i<s.length(); i++)
    {
        c[i] = s[i]-'a';
    }
    for(int i=0; i<s.length(); i++)
    {
        if(update(i))
        {
            r.push(i);
        }
    }
    while(true)
    {
        if(r.empty())
        {
            cout<<ans<<endl;
            return 0;
        }
        else
        {
            ans++;
            while(!r.empty())
            {
                v = r.front();
                r.pop();
                update2(v);
                g[v] = true;
            }
            for(int i=0; i<t.size(); i++)
            {
                if(update(t[i])&&!g[t[i]])
                {
                    r.push(t[i]);
                    g[t[i]] = true;
                }
            }
            t.clear();
        }
    }
}