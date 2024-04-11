#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int f(int n){
    if (n <= 8){

        cout << "a1 ";
        for (int i = 2; i < n; i++)
            cout << "a" << i << " ";
        cout << "a8 ";
        cout << "h8";
        return 0;

    }
    if (n <= 25){
        cout << "a1 ";
        for (int i = 2; i <= 8; i++){
            cout << "a" << i << " ";
        }
        n -= 8;
        if (n == 1){
            return cout << "b8 h8", 0;
        }
        if (n == 2){
            return cout << "b8 c8 h8", 0;
        }
        if (n == 3){
            return cout << "b8 b7 h7 h8", 0;
        }

        for (int i = 1; i <= n/2; i++){
            cout << "b" << 8-i+1 << " ";
        }
        for (int i = n/2; i >= 1; i--){
            cout << "c" << 8-i+1 << " ";
        }

        if (n % 2 == 1){
            cout << "d8 ";
        }
        cout << "h8";
        return 0;
    }
    if (n <= 41){
        n -= 25;
        cout << "a1 ";
        for (int i = 2; i <= 8; i++){
            cout << "a" << i << " ";
        }
        for (int i = 8; i >= 1; i--){
            cout << "b" << i << " ";
        }
        for (int i = 1; i <= 8; i++){
            cout << "c" << i << " ";
        }
        if (n == 1){
            return cout << "d8 e8 h8", 0;
        }
        if (n == 2){
            return cout << "d8 d7 h7 h8", 0;
        }
        ++n;
        for (int i = 1; i <= n/2; i++){
            cout << "d" << 8-i+1 << " ";
        }
        for (int i = n/2; i >= 1; i--){
            cout << "e" << 8-i+1 << " ";
        }
        if (n % 2 == 1){
            cout << "f8 ";
        }
        cout << "h8";
        return 0;
    }
    if (n <= 56){
        n -= 41;
        for (int i = 1; i <= 8; i++){
            cout << "a" << i << " ";
        }
        for (int i = 8; i >= 1; i--){
            cout << "b" << i << " ";
        }
        for (int i = 1; i <= 8; i++){
            cout << "c" << i << " ";
        }
        for (int i = 8; i >= 1; i--){
            cout << "d" << i << " ";
        }
        for (int i = 1; i <= 8; i++){
            cout << "e" << i << " ";
        }
        if (n == 1)
            return cout << "f8 g8 h8", 0;
        if (n == 2)
            return cout << "f8 f7 h7 h8", 0;
        ++n;
        if (n % 2 == 0){
            for (int i = 1; i <= n/2; i++){
                cout << "f" << 8-i+1 << " ";
            }
            for (int i = n/2; i >= 1; i--){
                cout << "g" << 8-i+1 << " ";
            }
        } else {
            for (int i = 1; i <= (n+1)/2; i++)
                cout << "f" << 8-i+1 << " ";
            int cur = 8-(n+1)/2+1;
            for (int i = 1; i <= n/2-1; i++){
                cout << "g" << cur << " ";
                ++cur;
            }
            cout << "g8 ";
        }
        cout << "h8";
        return 0;
    }
    if (n <= 62){
        for (int i = 1; i <= 8; i++){
            cout << "a" << i << " ";
        }
        for (int i = 8; i >= 1; i--){
            cout << "b" << i << " ";
        }
        for (int i = 1; i <= 8; i++){
            cout << "c" << i << " ";
        }
        for (int i = 8; i >= 1; i--){
            cout << "d" << i << " ";
        }
        for (int i = 1; i <= 8; i++){
            cout << "e" << i << " ";
        }
        for (int i = 8; i >= 1; i--){
            cout << "f" << i << " ";
        }
        for (int i = 1; i <= 4; i++){
            if (i % 2 == 1)
                cout << "g" << i << " h" << i << " "; else
                cout << "h" << i << " g" << i << " ";
        }
        if (n == 57)
            cout << "g8 h8"; else
        if (n == 58)
            cout << "g5 h5 h8"; else
        if (n == 59)
            cout << "g5 h5 h6 h8"; else
        if (n == 60)
            cout << "g5 h5 h6 h7 h8"; else
        if (n == 61)
            cout << "g5 h5 h6 g6 g8 h8"; else
        if (n == 62)
            cout << "g5 h5 h6 g6 g7 h7 h8";
        return 0;
    }
    for (char c = 'a'; c <= 'h'; c++)
        cout << c << 1 << " ";
    int cur = 0;
    for (char c = 'h'; c >= 'c'; c--){
        if (cur == 0){
            for (int i = 2; i <= 7; i++){
                cout << c << i << " ";
            }
        } else{
            for (int i = 7; i >= 2; i--)
                cout << c << i << " ";
        }
        cur ^= 1;
    }
    cur = 0;
    for (int i = 2; i <= 6; i++){
        if (cur == 0)
            cout << "b" << i << " a" << i << " "; else
            cout << "a" << i << " b" << i << " ";
        cur ^= 1;
    }
    cout << "a8 a7 b7 b8 ";
    for (char c = 'c'; c < 'h'; c++)
        cout << c << 8 << " ";
    cout << "h8";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    f(n);
    return 0;
    freopen("output.txt", "w", stdout);
    for (int i = 3; i <= 63; i++){
        f(i);
        cout << endl;
    }


}