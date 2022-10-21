#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n, k;
string str;
bool check() {

    for(int i = 0; i < n; i++) {
        if(str[i] > str[i % k]) return false;
        if(str[i] < str[i % k]) return true;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> str;

    cout << n << endl;
    if(check()) {
//        cout << "?" << endl;
        for(int i = 0; i < n; i++) cout << str[i % k];
    }
    else {
        int fir = -1;
        for(int i = 0; i < k; i++) {
            if(str[i] != '9') fir = i;
        }
        for(int i = 0; i < n; i++) {
            if(i % k == fir) cout << (char)(str[i % k] + 1 );
            else if(i % k < fir) cout << str[i % k];
            else cout << '0';
        }
    }


}