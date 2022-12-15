#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

bool is_prime(int x){
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 4; i <= n; ++i){
        int j = n - i;
        if(!is_prime(i) && !is_prime(j)){
            cout << i << " " << j << endl;
            return 0;
        }
    }
}