#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long LL;
int n , a[N];
set< pair<int , int> > Hash;
LL area;

int cover(pair<int , int> A , pair<int , int> B) {
    return A.first <= B.first && A.second >= B.second;
}
pair<int , int> intersection(pair<int , int> A , pair<int , int> B) {
    int x = max(A.first , B.first);
    int y = min(A.second , B.second);
    return {x , y};
}
LL count(pair<int , int> A) {
    int t = max(0 , A.second - A.first + 1);
    return (LL)t * (t + 1) / 2;
}
void insert(int x , int y) {
    if (y < x || x < 1 || x > n || y < 1 || y > n)
        return;
    pair<int , int> p(x , y);
    auto it = Hash.lower_bound(p);
    if (it != Hash.end() && cover(*it , p))
        return;
    pair<int , int> pre(0 , 0);
    if (it != Hash.begin()) {
        -- it;
        pre = *it;
        if (cover(*it , p))
            return;
        ++ it;
    }
    area += count(p);
    area -= count(intersection(pre , p));
    while (it != Hash.end() && cover(p , *it)) {
        area -= count(*it);
        area += count(intersection(pre , *it));
        pre = *it;
        Hash.erase(it ++);
    }
    if (it != Hash.end()) {
        area += count(intersection(pre , *it));
        area -= count(intersection(p , *it));
    }
    Hash.insert(p);
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d" , &x);
        a[x] = i;
    }
    LL res = 0;
    for (int i = N - 1 ; i >= 1 ; -- i) {
        vector<int> V;
        for (int j = i ; j < N ; j += i) {
            if (a[j]) {
                V.push_back(a[j]);
            }
        }
        if (V.size() > 1) {
            sort(V.begin() , V.end());
            int s = V.size();
            LL tmp = area;
            insert(V[1] + 1 , n);
            insert(1 , V[s - 2] - 1);
            insert(V[0] + 1 , V[s - 1] - 1);
            res += (area - tmp) * i;
        }
    }
    cout << res << endl;
}