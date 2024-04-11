#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int inf = (int)2e9;

int maxv, k;
int a[100100], b[100100], sz[100100], rmq[280100];

inline void update(int a, int b){
    a += maxv - 1;
    rmq[a] = b;
    while(a > 1){
        a /= 2;
        rmq[a] = max(rmq[a * 2], rmq[a * 2 + 1]);
    }
}

inline int find(int a){
    int l = 0;
    int r = k - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(b[mid] == a){
            return mid;
        }
        if(b[mid] < a){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}

inline void add(int a){
    int res = find(a);
    sz[res]++;
    if(sz[res] == 1){
        update(res, a);
    }
    else{
        update(res, -inf);
    }
}

inline void del(int a){
    int res = find(a);
    sz[res]--;
    if(sz[res] == 1){
        update(res, a);
    }
    else{
        update(res, -inf);
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
    sort(b, b + n);
    k = unique(b, b + n) - b;
    maxv = 1;
    while(maxv < k){
        maxv *= 2;
    }
    for(int i = 1; i < 2 * maxv; i++){
        rmq[i] = -inf;
    }
    for(int i = 0; i < m; i++){
        add(a[i]);
    }
    for(int i = 0; i <= n - m; i++){
        if(rmq[1] == -inf){
            printf("Nothing\n");
        }
        else{
            printf("%d\n", rmq[1]);
        }
        del(a[i]);
        add(a[i + m]);
    }
    return 0;
}