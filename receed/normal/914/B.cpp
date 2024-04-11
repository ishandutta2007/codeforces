#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int n, t, m = 100003;
    scanf("%d", &n);
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a[t]++;
    }
    for (int i = 0; i < m; i++)
        if (a[i] % 2) {
            printf("Conan");
            return 0;
        }
    printf("Agasa");
}