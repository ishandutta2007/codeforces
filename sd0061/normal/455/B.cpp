#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;

const int N = 100005;
int n , K;
char s[N];
int cnt , u[N][26];
bool leaf[N];

bool dfs(int x) {
    int cnt = 0;
    for (int i = 0 ; i < 26 ; ++ i) {
        if (!u[x][i])
            continue;
        cnt = 1;
        if (!dfs(u[x][i]))
            return 1;
    }
    if (!cnt) return 0;
    return 0;
}
bool DFS(int x) {
    int cnt = 0;
    for (int i = 0 ; i < 26 ; ++ i) {
        if (!u[x][i])
            continue;
        cnt = 1;
        if (!DFS(u[x][i]))
            return 1;
    }
    if (!cnt) return 1;
    return 0;
}


void work() {
    int i , j , x;
    scanf("%d%d",&n,&K);
    cnt = 1;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , s); x = 1;
        for (j = 0 ; s[j] ; ++ j) {
            int c = s[j] - 'a';
            if (!u[x][c]) {
                u[x][c] = ++ cnt;
            }
            x = u[x][c];
        }
    }
    bool f1 = dfs(1);
    bool f2 = DFS(1);
    //printf("%d %d\n" , f1 , f2);
    if (K == 1) {
        if (f1)
            puts("First");
        else
            puts("Second");
    } else {
        if (f2 && f1)
            puts("First");
        else if (f1 && !f2) {
            if (K & 1)
                puts("First");
            else
                puts("Second");
        } else
            puts("Second");


    }
}


int main()
{
    work();
    return 0;
}