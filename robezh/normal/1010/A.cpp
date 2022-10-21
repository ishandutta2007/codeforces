#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int a[N], b[N];
int num[2 * N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < 2 * n; i++){
        if(i % 2 == 0) num[i] = a[i/2];
        else num[i] = b[((i+1)/2)%n];
    }
    double now = m;
    for(int i = 2 * n - 1; i >= 0; i--){
        if(num[i] == 1) return !printf("-1");
        now += now / (num[i] - 1);
    }
    cout << fixed << setprecision(10) << now - m << endl;



}