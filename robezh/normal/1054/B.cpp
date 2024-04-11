#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n;
int num[N];
set<int> S;

int main(){
    for(int i = 0; i < N; i++) S.insert(i);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i] > *S.begin()) return !printf("%d", i + 1);
        S.erase(num[i]);
    }
    printf("-1");
}