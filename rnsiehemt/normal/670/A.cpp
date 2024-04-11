#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int main() {
    int n, a, b;
    scanf("%d", &n);
    a = b = n/7 * 2;
    if (n%7 >= 1) a++;
    if (n%7 >= 2) a++;
    if (n%7 >= 6) b++;
    //if (n%7 >= 6) b++;
    printf("%d %d\n", b, a);
}