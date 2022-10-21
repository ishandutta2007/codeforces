#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, s;
int r[N], l[N];
int u[N];


int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1; i <= n; i++) cin >> l[i];

    if(!r[1]) return !printf("NO");

    if(r[s] == 1) return !printf("YES");

    for(int i = s + 1; i <= n; i++){
        if(l[s] && l[i] && r[i]) return !printf("YES");
    }
    return !printf("NO");
}