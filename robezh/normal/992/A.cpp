#include <bits/stdc++.h>
using namespace std;

int n, a;
set<int> S;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        S.insert(a);
    }
    S.erase(0);
    printf("%d", S.size());
}