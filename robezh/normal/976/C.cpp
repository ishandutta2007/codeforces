#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)3e5 + 500;
typedef pair<int, int> P;
typedef pair<P, int> Ps;

int n;
Ps p[MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &p[i].first.first, &p[i].first.second);
        p[i].second = i;
    }
    sort(p, p+n);
    for(int i = 0; i < n-1; i++){
        if(p[i].first.first == p[i+1].first.first){
            return !printf("%d %d\n", p[i].second + 1, p[i+1].second + 1);
        }
        else if(p[i].first.second >= p[i+1].first.second){
            return !printf("%d %d\n", p[i+1].second + 1, p[i].second + 1);
        }
    }
    return !printf("-1 -1");
}