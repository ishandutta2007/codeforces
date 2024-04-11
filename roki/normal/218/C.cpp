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
    int n;
    cin >> n;
    int x[100],y[100];
    for(int i = 0;i < n;++i)
        cin >> x[i] >> y[i];
    bool used[100];
    memset(used,0,n);
    int ans = -1;
    for(int i = 0;i < n;++i)
    {
        if(!used[i])
        {
            ans++;
            used[i] = 1;
            queue<int> q;
            q.push(i);
            while(q.size() > 0)
            {
                int v = q.front();
                q.pop();
                for(int j = 0;j < n;++j)
                if(!used[j] && (x[v] == x[j] || y[v] == y[j]))
                {
                    used[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}