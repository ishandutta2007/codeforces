#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n;
int num[N];

bool is_prime(int t){
    for(int i = 2; i < t; i++) if(t % i == 0) return false;
    return true;
}

ll fp(int t, int k){
    if(k == 0) return 1;
    ll hf = fp(t, k/2);
    return k % 2 ? hf*hf%n*t%n : hf*hf%n;
}


int main(){
    cin >> n;
    if(!is_prime(n) && n > 4) return !printf("NO");
    cout << "YES" << endl;
    if(n == 4){
        cout << "1 3 2 4";
        return 0;
    }
    cout << 1 << " ";
    for(int i = 2; i < n; i++){
        ll res = i * fp(i-1, n-2) % n;
        cout << res << " ";
    }
    if(n > 1) cout << n;

}