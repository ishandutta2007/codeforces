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
    int n,x,a,b,c;
int f(int x)
{
    return (a * x + b) % c;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin >> n >> x >> a >> b >> c;
    vector<pair<int,string> > str;
    vector<vector<string>> v(4);
    for(int i = 0;i < n;++i)
    {
        int po;
        string s;
        cin >> s >> po;
        str.pb(mp(po,s));
    }
    sort(str.rbegin(),str.rend());
    for(int i = 0;i < n;++i)
        v[i / (n / 4)].pb(str[i].second);
    vector<vector<string>> ans(n / 4);
    for(int i = 0;i < n;++i)
    {
        x = f(x);
        ans[i / 4].pb(v[i % 4][x % v[i % 4].size()]);
        v[i % 4].erase(v[i % 4].begin() + x % v[i % 4].size());
    }
    for(int i = 0;i < n / 4;++i)
    {
        cout << "Group " << char('A' + i) << ':' << endl;
        for(int j = 0;j < 4;++j)
            cout << ans[i][j] << endl;
    }
    return 0;
}