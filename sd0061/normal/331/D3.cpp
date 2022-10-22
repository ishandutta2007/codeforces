#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200005;

struct arrow {
    int x0 , y0 , x1 , y1;
    int dx , dy , id;
    bool operator < (const arrow& R) const {
        return id < R.id;
    }
};
bool cmpX0(const arrow& A , const arrow& B) {
    return make_pair(max(A.x0 , A.x1) , -A.id) < make_pair(max(B.x0 , B.x1) , -B.id);
}
bool cmpX1(const arrow& A , const arrow& B) {
    return make_pair(-min(A.x0 , A.x1) , -A.id) < make_pair(-min(B.x0 , B.x1) , -B.id);
}
bool cmpY0(const arrow& A , const arrow& B) {
    return make_pair(max(A.y0 , A.y1) , -A.id) < make_pair(max(B.y0 , B.y1) , -B.id);
}
bool cmpY1(const arrow& A , const arrow& B) {
    return make_pair(-min(A.y0 , A.y1) , -A.id) < make_pair(-min(B.y0 , B.y1) , -B.id);
}

LL T[N];
arrow a[N];
int n , m , q;
int nxt[51][N];
LL t[51][N];
const LL inf = 1e16;
void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d%d%d" , &a[i].x0 , &a[i].y0 , &a[i].x1 , &a[i].y1);
        a[i].dx = a[i].x1 - a[i].x0;
        a[i].dy = a[i].y1 - a[i].y0;
        int len = abs(a[i].dx) + abs(a[i].dy);
        a[i].dx /= len , a[i].dy /= len;
        a[i].id = i;
    }
    scanf("%d" , &q);
    char dir[10];
    for (int i = n + 1 ; i <= n + q; ++ i) {
        scanf("%d%d" , &a[i].x0 , &a[i].y0);
        a[i].x1 = a[i].x0 , a[i].y1 = a[i].y0;
        a[i].id = i;
        scanf("%s%lld" , dir , &T[i]);
        if (*dir == 'U') a[i].dy = 1;
        if (*dir == 'D') a[i].dy = -1;
        if (*dir == 'R') a[i].dx = 1;
        if (*dir == 'L') a[i].dx = -1;        
    }
    multimap< int , arrow* > Hash;
    
    sort(a + 1 , a + n + q + 1 , cmpX0);
    Hash.clear();
    for (int i = 1 ; i <= n + q ; ++ i) {        
        if (a[i].id <= n) {
            int L = min(a[i].y0 , a[i].y1) , R = max(a[i].y0 , a[i].y1);
            auto it = Hash.lower_bound(L);
            auto itr = Hash.upper_bound(R);
            while (it != itr) {
                arrow *A = it -> second;
                nxt[0][A -> id] = a[i].id;
                t[0][A -> id] = abs(a[i].x1 - A -> x1) + abs(a[i].y1 - A -> y1);
                Hash.erase(it ++);
            }
        }
        if (a[i].dx == 1 && a[i].dy == 0)
            Hash.insert(make_pair(a[i].y0 , a + i));
    }
    for (auto &it : Hash) {
        arrow *A = it.second;
        nxt[0][A -> id] = 0;
        t[0][A -> id] = m - A -> x1;      
    }    
    sort(a + 1 , a + n + q + 1 , cmpX1);
    Hash.clear();
    for (int i = 1 ; i <= n + q ; ++ i) {
        if (a[i].id <= n) {
            int L = min(a[i].y0 , a[i].y1) , R = max(a[i].y0 , a[i].y1);
            auto it = Hash.lower_bound(L);
            auto itr = Hash.upper_bound(R);
            while (it != itr) {
                arrow *A = it -> second;
                nxt[0][A -> id] = a[i].id;
                t[0][A -> id] = abs(a[i].x1 - A -> x1) + abs(a[i].y1 - A -> y1);
                Hash.erase(it ++);
            }
        }
        if (a[i].dx == -1 && a[i].dy == 0)
            Hash.insert(make_pair(a[i].y0 , a + i));
    }
    for (auto &it : Hash) {
        arrow *A = it.second;
        nxt[0][A -> id] = 0;
        t[0][A -> id] = A -> x1;      
    }
    sort(a + 1 , a + n + q + 1 , cmpY0);
    Hash.clear();
    for (int i = 1 ; i <= n + q ; ++ i) {
        if (a[i].id <= n) {
            int L = min(a[i].x0 , a[i].x1) , R = max(a[i].x0 , a[i].x1);
            auto it = Hash.lower_bound(L);
            auto itr = Hash.upper_bound(R);
            while (it != itr) {
                arrow *A = it -> second;
                nxt[0][A -> id] = a[i].id;
                t[0][A -> id] = abs(a[i].x1 - A -> x1) + abs(a[i].y1 - A -> y1);
                Hash.erase(it ++);
            }
        }
        if (a[i].dx == 0 && a[i].dy == 1)
            Hash.insert(make_pair(a[i].x0 , a + i));
    }
    for (auto &it : Hash) {
        arrow *A = it.second;
        nxt[0][A -> id] = 0;
        t[0][A -> id] = m - A -> y1;      
    }
    sort(a + 1 , a + n + q + 1 , cmpY1);
    Hash.clear();
    for (int i = 1 ; i <= n + q ; ++ i) {
        if (a[i].id <= n) {
            int L = min(a[i].x0 , a[i].x1) , R = max(a[i].x0 , a[i].x1);
            auto it = Hash.lower_bound(L);
            auto itr = Hash.upper_bound(R);
            while (it != itr) {
                arrow *A = it -> second;
                nxt[0][A -> id] = a[i].id;
                t[0][A -> id] = abs(a[i].x1 - A -> x1) + abs(a[i].y1 - A -> y1);
                Hash.erase(it ++);
            }
        }
        if (a[i].dx == 0 && a[i].dy == -1)
            Hash.insert(make_pair(a[i].x0 , a + i));
    }
    for (auto &it : Hash) {
        arrow *A = it.second;
        nxt[0][A -> id] = 0;
        t[0][A -> id] = A -> y1;      
    }
    //for (int i = 1 ; i <= n + q ; ++ i)
    //    cout << i << ' ' << nxt[0][i] << ' ' << t[0][i] << endl;
    for (int j = 1 ; j <= 50 ; ++ j)
        for (int i = 0 ; i <= n + q ; ++ i) {
            nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
            t[j][i] = min(inf , t[j - 1][i] + t[j - 1][nxt[j - 1][i]]);
        }
    sort(a + 1 , a + n + q + 1);    
    for (int i = n + 1 ; i <= n + q ; ++ i) {
        int x = i;
        LL rt = T[i];
        for (int j = 50 ; j >= 0 ; -- j) {
            if (nxt[j][x] && t[j][x] <= rt) {
                rt -= t[j][x];
                x = nxt[j][x];
            }
        }
        int y = nxt[0][x];
        if (y && rt > (a[y].x1 - a[x].x1) * a[x].dx + (a[y].y1 - a[x].y1) * a[x].dy)
            rt -= t[0][x] , x = y;
        LL X = min((LL)m , max(0LL , a[x].x1 + rt * a[x].dx));
        LL Y = min((LL)m , max(0LL , a[x].y1 + rt * a[x].dy));
        printf("%d %d\n" , (int)X , (int)Y);
    }
    
}

int main() {
    work();
    return 0;
}