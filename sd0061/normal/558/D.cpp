#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int h , n;
vector< pair<LL , int> > V;

void work() {
    scanf("%d%d" , &h , &n);
    V.push_back({1LL << h - 1 , +1});
    V.push_back({1LL << h , -1});    
    for (int i = 0 ; i < n ; ++ i) {
        int d;
        LL l , r;
        scanf("%d%lld%lld" , &d , &l , &r);
        while (d < h) {
            l <<= 1;
            r <<= 1;
            ++ r;
            ++ d;
        }
        scanf("%d" , &d);
        if (!d) {
            V.push_back({0 , +1});
            V.push_back({l , -1});
            V.push_back({r + 1 , +1});
            V.push_back({1LL << 60 , -1});
        } else {
            V.push_back({l , +1});
            V.push_back({r + 1 , -1});
        }
    }
    sort(V.begin() , V.end());
    LL L = 0 , res = -1 , num = 0;
    int cnt = 0;   
    for (int i = 0 ; i < V.size() ; ++ i) {
        int j = i;
        while (j < V.size() && V[j].first == L) {
            cnt += V[j].second;
            ++ j;
        }
        if (j == V.size())
            break;
        if (cnt == n + 1) {
            num += V[j].first - L;
            if (V[j].first - L == 1)
                res = L;
        }
        i = j - 1;
        L = V[j].first;
    }
    if (num == 0)
        puts("Game cheated!");
    else if (num > 1)
        puts("Data not sufficient!");
    else
        printf("%lld\n" , res);
}

int main() {    
    work();
    return 0;
}