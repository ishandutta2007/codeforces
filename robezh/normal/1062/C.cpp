#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, mod = (int)1e9 + 7;
typedef long long ll;

string s;
int psum[2][N];
int n,q;
int pw2[N];


int get(int cnt1, int cnt0){
    ll enj = pw2[cnt1] - 1;
    enj = (enj + enj * (pw2[cnt0] - 1)) % mod;
    return (int)enj;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    pw2[0] = 1;
    for(int i = 1; i < N; i++) pw2[i] = pw2[i-1] * 2 % mod;

    cin >> n >> q;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            psum[j][i] = psum[j][i-1] + (s[i] - '0' == j);
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << get(psum[1][b] - psum[1][a-1], psum[0][b] - psum[0][a-1]) << endl;
    }

}