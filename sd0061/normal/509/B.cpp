#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int Q = 1e9 + 7;

int n , K , a[N];
vector<int> c[N];
void work() {
    int i , j;
    cin >> n >> K;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];

    for (i = 1 ; i <= K ; ++ i) {
        bool f = 0;
        do {
            for (j = 0 ; j < n ; ++ j) {
                if (c[j].size() < a[j])
                    c[j].push_back(i);
                else
                    f = 1;
            }
        } while (!f);        
    }
    for (i = 0 ; i < n ; ++ i)
        if (c[i].size() < a[i])
            break;
    if (i < n)
        puts("NO");
    else {
        puts("YES");
        for (i = 0 ; i < n ; ++ i) {
            for (auto k : c[i])
                printf("%d " , k);
            puts("");
        }
    }
}

int main() {
    work();
    return 0;
}