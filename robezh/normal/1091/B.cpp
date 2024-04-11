#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x = 0, y = 0;
int a, b;

int main(){
    scanf("%d", &n);
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a, &b);
            x += a, y += b;
        }
    }
    cout << x / n << " " << y / n << endl;
}