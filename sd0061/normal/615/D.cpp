#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n;
map<int , int> cnt;

int power(int A , int B) {
    int res = 1;
    while (B) {
        if (B & 1)
            res = (LL)res * A % Q;
        A = (LL)A * A % Q , B >>= 1;
    }
    return res;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        ++ cnt[x];
    }
    int E = 1;
    int M = (Q - 1) * 2;
    for (auto &it : cnt) {
        E = (LL)E * (it.second + 1) % M;
    }
    int res = 1;
    for (auto &it : cnt) {
        int B = (LL)E * it.second % M;
        res = (LL)res * power(it.first , B / 2) % Q;
    }
    cout << res << endl;    
    return 0;
}