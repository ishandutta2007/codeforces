#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    int now = v0;
    int pl = v0;
    int cnt = 1;
    while (now < c) {
        pl += a;
        pl = min(pl, v1);
        now += pl - l;
        cnt++;
    }
    cout << cnt;
}