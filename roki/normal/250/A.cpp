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
    int n,q = 0,t = 0;
    cin >> n;
    vint ans;
    for(int i = 0;i < n;++i)
    {
        int a;
        cin >> a;
        if(a < 0)
            q++;
        t++;
        if(q == 3)
        {
            ans.pb(t - 1);
            q = 1;
            t = 1;
        }
    }
    if(t > 0)
        ans.pb(t);
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();++i)
        cout << ans[i] << ' ';
    return 0;
}