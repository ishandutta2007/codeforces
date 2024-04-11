#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define N 100005
#define M 100005
int n , m , mcnt , pre[N];
struct edge
{
    int x , next;
}e[N << 1];

void work()
{
    int i , x , y;
    scanf("%d",&n);
    printf("%d\n" , n - 1);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        printf("2 %d %d\n" , x , y);
        e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {i , pre[y]} , pre[y] = mcnt ++;
    }
    for (x = 1 ; x <= n ; ++ x)
        for (i = pre[x] ; ~i && ~e[i].next ; i = e[i].next)
            printf("%d %d\n" , e[i].x , e[e[i].next].x);
}

int main()
{
    work();
    return 0;
}