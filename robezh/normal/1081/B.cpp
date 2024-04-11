#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
typedef pair<int, int> P;

int n;
P p[N];
int res[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i].first);
        p[i].first = n - p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    int r = 0;
    int cur = 1;
    for(int i = 0; i < n;){
        int k = p[i].first;
        while(r < i + k && r < n) r++;
        if(r - i != k || p[r-1].first != k) return !printf("Impossible");
        for(int j = i; j < r; j++){
            res[p[j].second] = cur;
        }
        cur++;
        i = r;
    }
    printf("Possible\n");
    for(int i = 0; i < n; i++) printf("%d ", res[i]);



}