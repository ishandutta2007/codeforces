#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
typedef long long LL;

int n , m;
set< pair<int , int> > e[N];
int deg[N] , res[N];
void dfs(int x) {

    while (!e[x].empty()) {
        auto edge = *e[x].begin();
        int y = edge.first , i = edge.second;
        e[x].erase(make_pair(y , i));
        e[y].erase(make_pair(x , i));
        dfs(y);
        res[i] = m ++;        
    }
    
}

int main() {
    int i , j , x , y;
    scanf("%d" , &n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &x , &y);
        y += 200000;
        e[x].insert(make_pair(y , i));
        e[y].insert(make_pair(x , i));       
        ++ deg[x] , ++ deg[y];
    }
    for (i = 1 ; i <= 400000 ; ++ i) {
        if (deg[i] & 1) {
            x = i;
            if (i <= 200000)
                y = 400001;
            else
                y = 400002;
            e[x].insert(make_pair(y , n));
            e[y].insert(make_pair(x , n));  
        }
    }
    for (i = 400002 ; i > 0 ; -- i)
        dfs(i);
    for (i = 0 ; i < n ; ++ i) {        
        putchar("rb"[res[i] & 1]);    
    }    
    puts("");
    return 0;
}