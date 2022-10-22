#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , a[N];
vector<int> res;
set< pair<int , int> > h[3];
void work() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        h[x % 3].insert(make_pair(x , i + 1));
    }
    int p0 = 0 , p1 = 1 , x = 0;
    while (res.size() < n) {
        auto it = h[x % 3].lower_bound(make_pair(x , -1));
        if (it == h[x % 3].end() || it -> first != x)
            break;
        res.push_back(it -> second);
        h[x % 3].erase(it);
        ++ x;
        it = h[x % 3].lower_bound(make_pair(x , 1 << 30));
        if (it == h[x % 3].begin())
            break;
        -- it;
        x = it -> first;        
    }
    if (res.size() < n)
        puts("Impossible");
    else {
        puts("Possible");
        for (int i = 0 ; i < n ; ++ i)
            printf("%d " , res[i]);
    }
}

int main() {
    work();
    return 0;
}