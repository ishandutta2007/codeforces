#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)2e5 + 500;

int n,m,d;
int num[N], res[N];
set<P> S;

int main(){
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        S.insert({num[i], i});
    }
    int curmin = 1;
    int now = -d-1;
    while(!S.empty()){
        auto it = S.lower_bound({now + d + 1, -1});
        if(it != S.end()){
            res[it->second] = curmin;
            now = it->first;
            S.erase(it);
        }
        else{
            now = -d-1;
            curmin++;
        }
    }
    printf("%d\n", curmin);
    for(int i = 0; i < n; i++) printf("%d ", res[i]);

}