#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define N 105
int n , p , m;
bool f[N];
void work()
{
    int i , j , k;
    scanf("%d%d",&n,&p);
    m = 2 * n + p;
    for (i = 1 ; m && i <= n ; ++ i) {
        for (j = 0 ; m && j < n ; ++ j){
            printf("%d %d\n" , j + 1 , (j + i) % n + 1);
            -- m;
        }
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}