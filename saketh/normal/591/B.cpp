#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
string orig;
char fin[256];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (char c = 'a'; c <= 'z'; c++) 
        fin[c] = c;

    cin >> N >> M;
    cin >> orig;

    for (int i = 0; i < M; i++) {
        char a, b;
        cin >> a >> b;

        for (int j = 0; j < 256; j++) {
            if (fin[j] == a) fin[j] = b;
            else if (fin[j] == b) fin[j] = a;
        }
    }

    for (char c : orig)
        cout << fin[c];
    cout << "\n";
}