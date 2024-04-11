#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int m, n;
    vector <int> vec;
    scanf("%d %d", &n, &m);
    while (n --) {
        int x;
        scanf("%d", &x);
        if (x < 0) vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int sum = 0, sz = vec.size();
    for (int i = 0; i < m && i < sz; i ++) sum -= vec[i];
    printf("%d\n", sum);
 
    return 0;
}