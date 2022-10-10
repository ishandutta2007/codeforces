#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b + 1) {
        cout << "NO\n";
        return 0;
    }
    if(d > c + 1) {
        cout << "NO\n";
        return 0;
    }
    if(a == b + 1) {
        if(c + d > 0) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        cout << "0 ";
        for(int i = 0; i < b; i++)
            cout << "1 0 ";
        cout << '\n';
        return 0;
    }
    if(d == c + 1) {
        if(a + b > 0) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        cout << "3 ";
        for(int i = 0; i < c; i++)
            cout << "2 3 ";
        cout << '\n';
        return 0;
    }
    //now b >= a, c >= d
    if(abs(a + c - b - d) > 1) {
        cout << "NO\n";
        return 0;
    }
    // a, a + k, b + k, b
    if(a + c == b + d) {
        cout << "YES\n";
        while(a--) {
            b--;
            cout << "0 1 ";
        }
        while(b--) {
            c--;
            cout << "2 1 ";
        }
        while(c--)
            cout << "2 3 ";
        cout << '\n';
        return 0;
    }
    // a, a + k, b + k + 1, b
    if(a + c == b + d + 1) {
        cout << "YES\n";
        cout << "2 ";
        c--;
        while(d--) {
            c--;
            cout << "3 2 ";
        }
        while(c--) {
            cout << "1 2 ";
            b--;
        }
        while(b--)
            cout << "1 0 ";
        cout << '\n';
        return 0;
    }
    cout << "YES\n";
    cout << "1 ";
    b--;
    while(a--) {
        b--;
        cout << "0 1 ";
    }
    while(b--) {
        c--;
        cout << "2 1 ";
    }
    while(c--)
        cout << "2 3 ";
    cout << '\n';
    return 0;
}