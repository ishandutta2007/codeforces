#include <bits/stdc++.h>
using namespace std;

int n;
int f[5005];
bool vis[5005];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> f[i];
        f[i]--;
    }

    for(int i = 0; i < n; i++){
        if(f[f[f[i]]] == i) return !printf("YES");
    }
    return !printf("NO");
}