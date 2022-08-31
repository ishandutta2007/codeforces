#include <iostream>
#include <set>

using namespace std;

const int MX = 200005;
int a[MX];
bool b[MX];
int n;

bool doit(int start) {
    if (start < 1 || start > n) return false;
    set<int> s;
    s.insert(start);
    for (int i = 0, v = start; i + 1 < n; i++) {
        v += a[i];
        if (v < 1 || v > n) return false;
        if (s.count(v)) return false;
        s.insert(v);
    }
    return true;
}

int main(){
    cin >> n;
    int s = 0, mn = 0;
    for (int i = 0; i + 1 < n; i++) {
        cin >> a[i];
        s += a[i];
        mn = min(mn, s);
    }
    int start = -mn + 1;
    if (!doit(start)) {
        cout << "-1\n";
    } else {
        int v = start;
        cout << v << " ";
        for (int i = 0; i + 1 < n; i++) {
            v += a[i];
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}