#include <bits/stdc++.h>
using namespace std;

string s, k;
int n, t;

void nn(char a, char b) {
    if (a != 'a' && b != 'a') {printf("a"); return;}
    if (a != 'b' && b != 'b') {printf("b"); return;}
    if (a != 'c' && b != 'c') {printf("c"); return;}
}

int eq, dif;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> t >> s >> k;
    for (int i = 0; i < n; i++)
        if (s[i] == k[i])
            eq++;
        else
            dif++;

    t = n - t;

    if (t > eq + dif / 2) {
        cout << "-1\n";
        return 0;
    }

    if (t <= eq) {
        for (int i = 0; i < n; i++)
            if (s[i] == k[i] && t) {
                t--;
                printf("%c", s[i]);
            } else {
                nn(s[i], k[i]);
            }
        return 0;
    } else {
        t -= eq;
        t *= 2;
        for (int i = 0; i < n; i++) {
            if (s[i] == k[i])
                printf("%c", s[i]);
            else if (s[i] != k[i] && t) {
                if (t % 2)
                    printf("%c", s[i]);
                else
                    printf("%c", k[i]);
                t--;
            } else 
                nn(s[i], k[i]);
        }
    }

    return 0;
}