#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    cin >> a;
    for(int b = 1; true; ++b){
        int x = a + b;
        bool has8 = false;
        while(x != 0){
            if(abs(x) % 10 == 8) has8 = true;
            x /= 10;
        }
        if(has8){
            cout << b << "\n";
            return 0;
        }
    }
}