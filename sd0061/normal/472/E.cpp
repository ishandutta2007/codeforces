#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <conio.h>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 35;
int n , m;
int a[N][N] , b[N][N];
int cnt[N * N] , d[N];

void solven() {
    int i , j , k;
    for (i = 1 ; i <= m ; ++ i) {
        int x = a[1][i];
        for (j = 1 ; j < i ; ++ j) {
            for (k = 1 ; k <= m ; ++ k)
                d[k] = a[1][k];
            for (k = i ; k > j ; -- k)
                d[k] = d[k - 1];
            d[j] = x;
            for (k = 1 ; k <= m ; ++ k)
                if (d[k] != b[1][k])
                    break;
            if (k > m) {
                printf("%d\n" , i - j);
                for (k = i ; k >= j ; -- k)
                    printf("%d %d\n" , 1 , k);
                return;
            }
        }
        for (j = i + 1 ; j <= m ; ++ j) {
            for (k = 1 ; k <= m ; ++ k)
                d[k] = a[1][k];
            for (k = i ; k < j ; ++ k)
                d[k] = d[k + 1];
            d[j] = x;
            for (k = 1 ; k <= m ; ++ k)
                if (d[k] != b[1][k])
                    break;
            if (k > m) {
                printf("%d\n" , j - i);
                for (k = i ; k <= j ; ++ k)
                    printf("%d %d\n" , 1 , k);
                return;
            }
        }
    }
    puts("-1");
}
void solvem() {
    int i , j , k;
    for (i = 1 ; i <= n ; ++ i) {
        int x = a[i][1];
        for (j = 1 ; j < i ; ++ j) {
            for (k = 1 ; k <= n ; ++ k)
                d[k] = a[k][1];
            for (k = i ; k > j ; -- k)
                d[k] = d[k - 1];
            d[j] = x;
            for (k = 1 ; k <= n ; ++ k)
                if (d[k] != b[k][1])
                    break;
            if (k > n) {
                printf("%d\n" , i - j);
                for (k = i ; k >= j ; -- k)
                    printf("%d %d\n" , k , 1);
                return;
            }
        }
        for (j = i + 1 ; j <= n ; ++ j) {
            for (k = 1 ; k <= n ; ++ k)
                d[k] = a[k][1];
            for (k = i ; k < j ; ++ k)
                d[k] = d[k + 1];
            d[j] = x;
            for (k = 1 ; k <= n ; ++ k)
                if (d[k] != b[k][1])
                    break;
            if (k > n) {
                printf("%d\n" , j - i);
                for (k = i ; k <= j ; ++ k)
                    printf("%d %d\n" , k , 1);
                return;
            }
        }
    }
    puts("-1");
}

vector< pair<int , int> > res;

void moveup(int x , int y) {
    int i = x - 1 , j , u , v;
    if (y > 1)
        j = y - 1;
    else
        j = y + 1;
    u = v = 1;
    while (v < j) {
        swap(a[u][v] , a[u][v + 1]);
        res.push_back(make_pair(u , v + 1));
        ++ v;
    }
    while (u < i) {
        swap(a[u][v] , a[u + 1][v]);
        res.push_back(make_pair(u + 1 , v));
        ++ u;
    }
    swap(a[i][j] , a[x][y]);
    res.push_back(make_pair(x , y));
    swap(a[x][y] , a[x - 1][y]);
    res.push_back(make_pair(x - 1 , y));
    swap(a[x - 1][y] , a[i][j]);
    res.push_back(make_pair(i , j));
    while (u > 1) {
        swap(a[u][v] , a[u - 1][v]);
        res.push_back(make_pair(u - 1 , v));
        -- u;
    }
    while (v > 1) {
        swap(a[u][v] , a[u][v - 1]);
        res.push_back(make_pair(u , v - 1));
        -- v;
    }
}
void moveleft(int x , int y) {
    int i , j = y - 1 , u , v;
    if (x > 1)
        i = x - 1;
    else
        i = x + 1;
    u = v = 1;
    while (u < i) {
        swap(a[u][v] , a[u + 1][v]);
        res.push_back(make_pair(u + 1 , v));
        ++ u;
    }
    while (v < j) {
        swap(a[u][v] , a[u][v + 1]);
        res.push_back(make_pair(u , v + 1));
        ++ v;
    }
    swap(a[i][j] , a[x][y]);
    res.push_back(make_pair(x , y));
    swap(a[x][y] , a[x][y - 1]);
    res.push_back(make_pair(x , y - 1));
    swap(a[x][y - 1] , a[i][j]);
    res.push_back(make_pair(i , j));
    while (v > 1) {
        swap(a[u][v] , a[u][v - 1]);
        res.push_back(make_pair(u , v - 1));
        -- v;
    }
    while (u > 1) {
        swap(a[u][v] , a[u - 1][v]);
        res.push_back(make_pair(u - 1 , v));
        -- u;
    }
}
void movedownleft(int x , int y) {
    int i = x , j = y - 1 , u , v;
    u = v = 1;
    while (v < j) {
        swap(a[u][v] , a[u][v + 1]);
        res.push_back(make_pair(u , v + 1));
        ++ v;
    }
    while (u < i) {
        swap(a[u][v] , a[u + 1][v]);
        res.push_back(make_pair(u + 1 , v));
        ++ u;
    }
    swap(a[i][j] , a[x][y]);
    res.push_back(make_pair(x , y));
    swap(a[x][y] , a[x + 1][y - 1]);
    res.push_back(make_pair(x + 1 , y - 1));
    swap(a[x + 1][y - 1] , a[i][j]);
    res.push_back(make_pair(i , j));
    while (u > 1) {
        swap(a[u][v] , a[u - 1][v]);
        res.push_back(make_pair(u - 1 , v));
        -- u;
    }
    while (v > 1) {
        swap(a[u][v] , a[u][v - 1]);
        res.push_back(make_pair(u , v - 1));
        -- v;
    }
}

void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d",&a[i][j]) , ++ cnt[a[i][j]];
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d",&b[i][j]) , -- cnt[b[i][j]];
    {
    for (i = 1 ; i <= 900 ; ++ i)
        if (cnt[i])
            break;
    if (i <= 900) {
        puts("-1");
        return;
    }
    if (n == 1) {
        solven();
        return;
    }
    if (m == 1) {
        solvem();
        return;
    }
    }
    x = y = -1;
    for (i = 1 ; i <= n && !~x ; ++ i)
        for (j = 1 ; j <= m && !~x ; ++ j)
            if (a[i][j] == b[1][1])
                x = i , y = j;
    res.push_back(make_pair(x , y));
    while (x > 1) {
        swap(a[x - 1][y] , a[x][y]);
        res.push_back(make_pair(x - 1 , y));
        -- x;
    }
    while (y > 1) {
        swap(a[x][y - 1] , a[x][y]);
        res.push_back(make_pair(x , y - 1));
        -- y;
    }
    for (i = n ; i > 0 ; -- i)
        for (j = m ; j > 0 ; -- j) {
            for (k = m * (i - 1) + j ; k > 0 ; -- k) {
                x = (k - 1) / m + 1 , y = (k - 1) % m + 1;
                if (a[x][y] == b[i][j])
                    break;
            }
            assert(k > 0);
            while (y > j && x + y > i + j) {
                moveleft(x , y);
                -- y;
            }
            while (x < i && y > j) {
                movedownleft(x , y);
                ++ x , -- y;
            }
            while (y < j) {
                moveleft(x , y + 1);
                ++ y;
            }
            while (y > j) {
                moveleft(x , y);
                -- y;
            }
            while (x < i) {
                moveup(x + 1 , y);
                ++ x;
            }
        }
    printf("%d\n" , res.size() - 1);
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d %d\n" , res[i].first , res[i].second);
}

int main() {
    work();
    return 0;
}