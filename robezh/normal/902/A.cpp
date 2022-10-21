#include <bits/stdc++.h>
using namespace std;

int n,m;
int loc[105];


int main() {
    fill(loc, loc+105, 0);
    cin >> n >> m;
    int a,b;
    for(int i = 0; i< n; i++){
        cin >> a >> b;
        for(int j = a + 1; j <= b; j++){
            loc[j] = 1;
        }
    }
    for(int i = 1; i <= m; i++){
        if(loc[i] == 0) return !printf("NO");
    }
    return !printf("YES");
}