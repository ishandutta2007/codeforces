#include <bits/stdc++.h>
using namespace std;

int x, hh, mm;
int t;

bool check(int t0){
    int h = t0 / 60, w = t0 % 60;
    return (h % 10 == 7 || w % 10 == 7);
}

int main() {
    cin >> x >> hh >> mm;
    t = hh * 60 + mm;
    int ans = 0;
    while(true){
        if(check(t)) return !printf("%d", ans);
        t = (t + 1440 - x) % 1440;
        ans++;
    }
}