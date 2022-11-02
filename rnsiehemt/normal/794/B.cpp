#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n;
double h;

int main() {
    scanf("%d%lf", &n, &h);
    for (int i = 1; i < n; i++) {
        printf("%.8lf%c", std::sqrt(double(i) / n) * h, " \n"[i == n-1]);
    }
}