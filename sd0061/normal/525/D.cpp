#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;
int n , m , id[N][N] , num;
char str[N][N];
int dx[] = {0 , 1 , 0 , -1} , dy[] = {1 , 0 , -1 , 0};
int f[N * N] , mx[N * N] , my[N * N] , nx[N * N] , ny[N * N];
set<int> B[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
void merge(int x , int y) {
    x = getf(x) , y = getf(y);
    if (x != y) {
        f[x] = y;
        mx[y] = max(mx[y] , mx[x]);
        nx[y] = min(nx[y] , nx[x]);
        my[y] = max(my[y] , my[x]);
        ny[y] = min(ny[y] , ny[x]);        
    }
}
bool vaild[N];

void Add(int i , int j) {
    f[id[i][j]] = id[i][j];
    for (int k = 0 ; k < 4 ; ++ k) {
        int x = i + dx[k] , y = j + dy[k];
        if (str[x][y] == '.')
            merge(id[x][y] , id[i][j]);
    }
}

bool Erase(int x) {
    bool rep = 0;
    vector<int> e;
    //printf("%d %d %d %d\n" , nx[x] , mx[x] , ny[x] , my[x]);
    for (int i = nx[x] ; i <= mx[x] ; ++ i) {
        for (auto it = B[i].lower_bound(ny[x]) ; ; ++ it) {
            if (it == B[i].end() || *it > my[x])
                break;
            //cout << i << ' ' << *it << endl;
            str[i][*it] = '.';
            Add(i , *it);
            e.push_back(*it);
            rep = 1;
        }
        while (!e.empty())
            B[i].erase(e.back()) , e.pop_back();
    }
    return rep;
}

void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , str[i] + 1);

    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            id[i][j] = ++ num;
            nx[num] = mx[num] = i;
            ny[num] = my[num] = j;            
            if (str[i][j] == '*')
                B[i].insert(j) , f[num] = 0;
            else
                f[num] = num;
        }

    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            if (str[i][j] == '*')
                continue;
            for (k = 0 ; k < 4 ; ++ k) {
                x = i + dx[k] , y = j + dy[k];
                if (str[x][y] == '.')
                    merge(id[x][y] , id[i][j]);
            }
        }
    queue<int> Q;
    for (i = 1 ; i <= num ; ++ i) {
        if (getf(i) == i)
            Q.push(i);
    }
    while (!Q.empty()) {
        i = Q.front() , Q.pop();
        if (getf(i) != i)
            continue;
        while (Erase(i))
            i = getf(i);                
    }
    for (i = 1 ; i <= n ; ++ i)
        puts(str[i] + 1);
    
    
}

int main() {
    work();
    return 0;
}