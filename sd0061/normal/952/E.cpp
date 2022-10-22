#include <bits/stdc++.h>
using namespace std;
const int N = 55;

char str[N];

int main() {
    map<string , string> m;
    m["brie"] = "soft";
    m["camembert"] = "soft";
    m["muenster"] = "soft";
    m["goat"] = "soft";

    m["asiago"] = "hard";
    m["cheddar"] = "hard";
    m["swiss"] = "hard";
    m["gouda"] = "hard";
    m["feta"] = "hard";


    int cnt = 0, n;
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        string s , t;
        cin >> s >> t;
        if (t != "hard") {
            ++ cnt;
        }
    }
    if (cnt < n - cnt) {
        cnt = n - cnt;
    }

    int i = 1;
    while (1) {
        if (cnt <= (i * i + 1) / 2 && n - cnt <= i * i / 2) {
            cout << i << endl;
            return 0;
        }
        ++ i;
    }
}