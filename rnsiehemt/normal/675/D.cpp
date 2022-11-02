#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, a;
std::set<int> s;
std::map<int, int> d;

int main() {
    scanf("%d%d", &n, &a);
    s.insert(a);
    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        auto right = s.lower_bound(a);
        auto left = right;
        if (left != s.begin()) left--;
        if (right == s.end()) right--;
        //printf("i = %d, a = %d, *left = %d, *right = %d\n", i, a, *left, *right);
        if (d[*right] > d[*left]) left = right;
        d[a] = d[*left] + 1;
        printf("%d%c", *left, " \n"[i == n-1]);
        s.insert(a);
    }
}