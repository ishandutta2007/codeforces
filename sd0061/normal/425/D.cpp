#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 100005
int n;
int M = 333;
pair<int , int> a[N];
vector<int> X[N];
int ans;
int pre[1000003] , mcnt;
struct node {
    int x , y , next;
}e[N];
int hash(int x , int y) {
    return (x * 139 + y * 911) % 1000003;
}
void insert(int x , int y) {
    int h = hash(x , y);
    e[mcnt] = (node) {x , y , pre[h]} , pre[h] = mcnt ++;
}
bool count(int x , int y) {
    for (int i = pre[hash(x , y)] ; ~i ; i = e[i].next)
        if (e[i].x == x && e[i].y == y)
            return 1;
    return 0;
}


void work() {
    int i , j , k , x , y , L;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&x,&y);
        X[x].push_back(y);
        insert(x , y);
        a[i] = make_pair(x , y);
    }
    sort(a + 1 , a + 1 + n);
    for (i = 0 ; i <= 100000 ; ++ i)
        sort(X[i].begin() , X[i].end());
    for (i = 0 ; i <= 100000 ; ++ i) {
        if (X[i].size() >= M) {
            for (j = 1 ; j <= n ; ++ j) {
                if (a[j].first == i) continue;
                x = a[j].first , y = a[j].second;
                if (count(i , y)) {
                    L = abs(x - i);
                    if (count(i , y + L) && count(x , y + L)) {
                        ++ ans;
                        if (x < i && X[x].size() >= M)
                            -- ans;
                    }
                }
            }
        } else {
            for (j = 0 ; j < X[i].size() ; ++ j)
                for (k = j + 1 ; k < X[i].size() ; ++ k) {
                    int L = X[i][k] - X[i][j];
                    if (!L) continue;
                    if (i + L <= 100000 && X[i + L].size() < M) {
                        ans += count(i + L , X[i][j]) && count(i + L , X[i][k]);
                    }
                }
        }
    }
    printf("%d\n" , ans);
}

int main(){
    work();
    return 0;
}