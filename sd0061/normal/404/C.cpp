#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <set>
#include <map>
typedef long long LL;
using namespace std;
#define N 100005

int n , K;
int deg[N];
pair<int , int> d[N];
vector< pair<int , int> > res;
queue<int> Q[N];

void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&d[i].first) , d[i].second = i;
    sort(d + 1 , d + 1 + n);
    if (d[1].first || !d[2].first) {
        puts("-1");
        return;
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (!d[i].first) {
            Q[0].push(d[i].second);
            continue;
        }
        j = d[i].first - 1 , x = d[i].second;
        while (!Q[j].empty() && deg[Q[j].front()] >= K)
            Q[j].pop();
        if (Q[j].empty())
            break;
        y = Q[j].front();
        res.push_back(make_pair(x , y));
        ++ deg[y] , ++ deg[x];
        Q[j + 1].push(x);
    }
    if (i <= n)
        puts("-1");
    else {
        printf("%d\n" , res.size());
        for (i = 0 ; i < res.size() ; ++ i)
            printf("%d %d\n" , res[i].first , res[i].second);
    }
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}