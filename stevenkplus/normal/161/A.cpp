// http://codeforces.com/problemset/problem/160/A
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

pair<int, int> soldiers[MAXN];
pair<int, int> vests[MAXN];
int answers1[MAXN];
int answers2[MAXN];

int main() {
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        soldiers[i] = pair<int, int>(a, i + 1);
    }
    for (int i = 0; i < m; ++i) {
        int a; // scanf("%d", vests[i].first);
        scanf("%d", &a);
        vests[i] = pair<int, int>(a, i + 1);
    }

    sort(soldiers, soldiers + n);
    sort(vests, vests + m);

    int counter = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        int a = soldiers[i].first;
        int b = vests[j].first;
        
        if (a < b - y) {
            ++i;
        } else if (a > b + x) {
            ++j;
        } else {
            answers1[counter] = soldiers[i].second;
            answers2[counter] = vests[j].second;
            ++counter;
            ++i;
            ++j;
        }
    }
    
    printf("%d\n", counter);
    for (int i = 0; i < counter; ++i) {
        printf("%d %d\n", answers1[i], answers2[i]);
    }
    
    return 0;
}