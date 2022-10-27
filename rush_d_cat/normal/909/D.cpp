#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1000000+10;


char s[N];
bool vis[N];
int pre[N], nxt[N], dis[N], n;

vector<int> v;
queue<int> que;

void tackel() {
    if (v.size() == 0) return;

    int L = v[0], R = v[0];
    //printf("%d %d\n", L, R);
    for (int i = 1; i < v.size(); i ++) 
    {
        if (v[i] != nxt[v[i-1]] || i == (int)v.size()-1) 
        {
            R = (v[i] != nxt[v[i-1]]) ? v[i-1] : v[i];
            pre[ nxt[R] ] = pre[L];
            nxt[ pre[L] ] = nxt[R];
            //printf("L=%d, R=%d\n", L, R);
            //printf("pL = %d, nR = %d\n", pre[L], nxt[R]);
            if (pre[L] > 0 && nxt[R] < n+1 && s[pre[L]] != s[nxt[R]]) 
            {
                if (vis[pre[L]] == 0)
                    que.push(pre[L]);

                if (vis[nxt[R]] == 0)
                    que.push(nxt[R]); 
                
                vis[pre[L]] = vis[nxt[R]] = 1;
            }
            L = v[i];
        } 
    }
}

int main() {
    scanf("%s", s+1);
    n = strlen(s+1);
    for (int i = 1; i <= n; i ++) {
        pre[i] = i-1;
        nxt[i] = i+1;
    }

    for (int i = 1; i < n; i ++) {
        if (s[i] != s[i+1]) {
            vis[i] = vis[i+1] = 1;
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) que.push(i);
    }

    int ans = 0;
    while (que.size()) {

        v.clear();
        while(que.size()) {
            v.push_back(que.front()); 
            //printf("que: %d\n", que.front());
            que.pop();
        }
        //printf("que: ------\n");
        tackel(); ans ++;
    }

    printf("%d\n", ans);
}