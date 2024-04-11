#include <bits/stdc++.h>
using namespace std;

int n;
int num[1505];
int m;
int a,b;
bool even = true;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(num[i] > num[j]){
                even = !even;
            }
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        int k = b - a + 1;
        int cnt = k * (k-1) / 2;
        even = (cnt % 2 == 0 ? even : !even);
        printf(even ? "even\n" : "odd\n");
    }

    return 0;
}