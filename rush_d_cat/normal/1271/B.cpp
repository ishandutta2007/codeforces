#include <iostream>
#include <vector>
using namespace std;
const int N = 202;
int n;
char s[N], t[N];

int main() {
    scanf("%d%s", &n, s+1);
    for (int i = 1; i <= n; i ++) t[i] = s[i];

    {
        vector<int> v;
        for (int i = 2; i < n; i ++) {
            if (t[i] != t[1]) {
                t[i] = 'B' + 'W' - t[i];
                t[i + 1] = 'B' + 'W' - t[i + 1];
                v.push_back(i);
            }
        }
        if (t[n] == t[1]) {
            printf("%d\n", v.size());
            for (auto x: v) printf("%d ", x);
            return 0;
        }
    }


    {
        vector<int> v;
        for (int i = 1; i <= n; i ++) t[i] = s[i];
        t[1] = 'B' + 'W' - t[1];
        t[2] = 'B' + 'W' - t[2];
        v.push_back(1);
        for (int i = 2; i < n; i ++) {
            if (t[i] != t[1]) {
                t[i] = 'B' + 'W' - t[i];
                t[i + 1] = 'B' + 'W' - t[i + 1];
                v.push_back(i);
            }
        }
        if (t[n] == t[1]) {
            printf("%d\n", v.size());
            for (auto x: v) printf("%d ", x);
            return 0;
        }
    }
    printf("-1\n");
}