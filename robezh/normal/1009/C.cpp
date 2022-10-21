#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
typedef long double ld;

int n,m;
int num[N];
int x[N], d[N];
long long adda = 0;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> x[i] >> d[i];
    for(int i = 0; i < m; i++) adda += 1LL * n * x[i];
    for(int i = 0; i < m; i++){
        if(d[i] < 0){
            adda += 1LL * d[i] * (n % 2 == 1 ? 1LL * (n-1)*(n+1)/4 : 1LL*(n-2)*(n)/8 + 1LL*(n)*(n+2)/8);
        }
        else{
            adda += 1LL * d[i] * n * (n-1) / 2;
        }
    }
    //cout << adda << endl;
    cout << fixed << setprecision(10) << (double)adda / n;
}