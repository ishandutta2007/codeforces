#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int cnt[10];

int main() {
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
        string s;
        getline(cin, s);
        if (s == "no") continue;
        if (s != "don't even" && s != "terrible" && s != "worse" && s != "go die in a hole" && s != "no way" && s != "are you serious") {
            cout << "normal" << endl;
            return 0;
        }
        cout << "grumpy" << endl;

    }
}