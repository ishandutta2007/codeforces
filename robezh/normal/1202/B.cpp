#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int solve(int a, int b, int d) {
    int mn = INF;
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) {
            if(i + j == 0) continue;
            if((a * i + b * j) % 10 == d) mn = min(i + j - 1, mn);
        }
    }
    return mn;
}

string str;
int cnt[10];

int get_ans(int a, int b) {
    int res = 0;
    for(int i = 0; i < 10; i++) {
        int add = solve(a, b, i);
        if(cnt[i] > 0 && add == INF) return -1;
        res += add * cnt[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    for(int i = 1; i < str.length(); i++) {
        int cur = (str[i] + 10 - str[i-1]) % 10;
        cnt[cur]++;
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << get_ans(i, j) << " ";
        }
        cout << "\n";
    }
}