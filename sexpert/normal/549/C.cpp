#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void win(int x) {
    if(x == 1)
        cout << "Stannis\n";
    else
        cout << "Daenerys\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, a = 0, b = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x % 2)
            b++;
        else
            a++;
    }
    int turns = n - k;
    if(!turns) {
        if(b % 2)
            win(1);
        win(2);
    }
    if(turns % 2 == 0) {
        if(turns/2 < a)
            win(2);
        if(k % 2)
            win(1);
        win(2);
    }
    if(turns / 2 >= b)
        win(2);
    if(turns / 2 < a)
        win(1);
    if(k % 2)
        win(1);
    win(2);
}