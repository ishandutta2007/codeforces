#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 18) + 500;
typedef long long ll;
typedef long double ld;

int n,r;
int num[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> r;

    ll sum = 0;
    for(int i = 0; i < (1 << n); i++) cin >> num[i], sum += num[i];

    cout << fixed << setprecision(10) << (double)sum / (1 << n) << "\n";
    for(int i = 0; i < r; i++){
        int a, b;
        cin >> a >> b;
        sum -= num[a], sum += b;
        num[a] = b;
        cout << fixed << setprecision(6) << (double)sum / (1 << n);
        if(i < r-1) cout << "\n";
        else cout << endl;
    }
}