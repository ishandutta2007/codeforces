#include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;
int n, a[N], sa[N];
int m, b[N], sb[N];
vector<int> ans;
int f(int x) {
    if (x > n) return b[x-n];
    return a[x];
}

int solve1() {
    ans.clear();
    int p1 = 1, p2 = 1;
    while (p1 <= n || p2 <= m) {
        while (p1 <= n && a[p1] == 1) ans.push_back(p1), p1 ++;
        while (p2 <= m && b[p2] == 1) ans.push_back(p2+n), p2 ++;
        while (p1 <= n && a[p1] == 0) ans.push_back(p1), p1 ++;
        while (p2 <= m && b[p2] == 0) ans.push_back(p2+n), p2 ++;
    } 
    int cnt = 0;
    for (int i = 0; i < ans.size(); i ++) {
        if ( (i == (int)ans.size()-1 && f(ans[i]) == 1) || 
            ((i < (int)ans.size()-1) && f(ans[i]) != f(ans[i+1])) )
            cnt ++;
    }
    return cnt;
}

int solve2() {
    ans.clear();
    int p1 = 1, p2 = 1;
    while (p1 <= n || p2 <= m) {
        while (p1 <= n && a[p1] == 0) ans.push_back(p1), p1 ++;
        while (p2 <= m && b[p2] == 0) ans.push_back(p2+n), p2 ++;
        while (p1 <= n && a[p1] == 1) ans.push_back(p1), p1 ++;
        while (p2 <= m && b[p2] == 1) ans.push_back(p2+n), p2 ++;
    } 
    int cnt = 0;
    for (int i = 0; i < ans.size(); i ++) {
        if ( (i == (int)ans.size()-1 && f(ans[i]) == 1) || 
            ((i < (int)ans.size()-1) && f(ans[i]) != f(ans[i+1])) )
            cnt ++;
    }
    return cnt;
} 

int main() {
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) 
        scanf("%d", &b[i]);

    for (int i = n; i >= 1; i --) {
        if (a[i] == 0) sa[i] = 1;
        else break;
    }
    for (int i = m; i >= 1; i --) {
        if (b[i] == 0) sb[i] = 1;
        else break;
    }

    int cnt = 0;
    if (solve1() < solve2()) {
        cnt = solve1();
    } else {
        cnt = solve2();
    }
    for (int i = 0; i < ans.size(); i ++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    for (int i = 0; i < ans.size(); i ++) {
        if ( (i == (int)ans.size()-1 && f(ans[i]) == 1) || 
            ((i < (int)ans.size()-1) && f(ans[i]) != f(ans[i+1])) )
            printf("%d ", i+1);
    }
    printf("\n");
}