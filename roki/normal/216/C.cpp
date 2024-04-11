#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long LL;
#define vint vector<int>
using namespace std;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    queue<int> q,qq;
    vint ans;
    for(int i = 1;i < 4 * (n + m);++i)
    {
        while(qq.size() > 0 && (i - qq.front() == m))
        {
            q.push(i);
            qq.pop();
        }
        while(q.size() > 0 && (i - q.front() == n))
        {
            q.pop();
            qq.push(i);
        }
        while(q.size() < k || (i - q.back() + 1 == n))
        {
            q.push(i);
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();++i)
        cout << ans[i] << ' ';
    return 0;
}