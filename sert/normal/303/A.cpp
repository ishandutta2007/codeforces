#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, x, ans;
string s;
char lst;
int a[100010];
bool u[100100];
bool u2[100100];

void go(int len) {
    if (len == n) {
        for (int i = 0; i < n; i++)
            cout << i << " ";
        cout << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; i++)
            cout << (i + a[i]) % n << " ";
        exit(0);
    }
    for (int i = 0; i < n; i++)
        if (!u[i] && !u2[(i + len) % n]) {
            u[i] = true;
            u2[(i + len) % n] = true;
            a[len] = i;
            go(len + 1);
            u[i] = false;
            u2[(i + len) % n] = false;
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i] = i;
    if (n % 2 == 0)
        cout << -1;
    else
        go(n);
    return 0;
}