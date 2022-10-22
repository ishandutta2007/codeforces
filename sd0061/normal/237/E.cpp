#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define N 1005
#define M 100005
int n , m;
int s , t , ans , maxflow;
int pre[N] , mcnt;
struct arc
{
  int x , f , c , next;
}e[M];

void addarc(int x ,int y ,int z ,int c)
{
    e[mcnt] = (arc){y , z , c , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc){x , 0 , -c , pre[y]} , pre[y] = mcnt ++;
}

int d[N] , p[N];
bool f[N];
deque<int> q;

bool Bellman_Ford()
{
    int i , x , y , z;
    memset(f , 0 , sizeof(f));
    for (i = 0 ; i <= t ; ++ i) d[i] = 1 << 30;
    d[s] = 0 , f[s] = 1 , q.push_back(s);
    while (!q.empty())
    {
        x = q.front() , q.pop_front() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next)
        {
            y = e[i].x , z = e[i].c;
            if (e[i].f && d[y] > d[x] + z)
            {
                d[y] = d[x] + z , p[y] = i;
                if (!f[y])
                {
                    if (q.empty() || d[y] < d[q.front()])
                        q.push_front(y);
                    else q.push_back(y);
                    f[y] = 1;
                }
            }
        }
    }
    return d[t] != 1 << 30;
}

int Mincostflow()
{
    maxflow = 0 , ans = 0;
    int x;
    while (Bellman_Ford())
    {
        int flow = 1 << 30;
        for (x = t ; x != s ; x = e[p[x] ^ 1].x)
            flow = min(flow , e[p[x]].f);
        maxflow += flow , ans += d[t] * flow;
        for (x = t ; x != s ; x = e[p[x] ^ 1].x)
            e[p[x]].f -= flow , e[p[x] ^ 1].f += flow;
    }
    if (maxflow != m)
        return -1;
    return ans;
}
char T[N];
int cnt[26];
void work()
{
    int i , j , x , y;
    scanf("%s%d", T,&n);
    memset(pre , - 1, sizeof(pre));
    for (i = 0 ; T[i] ; ++ i)
        ++ cnt[T[i] - 'a'] , ++ m;
    s = 26 + n , t = s + 1;
    for (i = 0 ; i < 26 ; ++ i) if (cnt[i])
        addarc(i , t , cnt[i] , 0);
    for (i = 0 ; i < n ; ++ i)
    {
        memset(cnt , 0 ,sizeof(cnt));
        scanf("%s%d", T , &x);
        addarc(s , 26 + i , x , i + 1);
        for (j = 0 ; T[j] ; ++ j)
            ++ cnt[T[j] - 'a'];
        for (j = 0 ; j < 26 ; ++ j) if (cnt[j])
            addarc(26 + i , j , cnt[j] , 0);
    }
    cout << Mincostflow() << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}