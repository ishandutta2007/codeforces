#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    int n,c[100000],m;
    cin >> n >> m;
    vector<bool> l(100001,0);
    for(int i = 0 ;i < n;++i)
    {
        cin >> c[i];
        l[c[i]] = 1;
    }
    vector< set<int> > g(100001);
    for(int i = 0;i < m;++i)
    {
        int a,b;
        cin >> a >> b;
        if(c[a - 1] == c[b - 1])
            continue;
        g[c[--a]].insert(c[--b]);
        g[c[b]].insert(c[a]);
    }
    int k = 0,ans = c[0];
    for(int i = 0;i < 100001;++i)
    {
        if(!l[i])
            continue;
        g[i].size();
        if(g[i].size() == k)
            ans = min(ans,i);
        if(g[i].size() > k)
        {
            k = g[i].size();
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}