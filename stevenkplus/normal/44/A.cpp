#include <iostream>
#include <set>

using namespace std;

set<string> myset;
int N;

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;
        myset.insert(a + " " + b);
    }
    int ans = int(myset.size());
    cout << ans << endl;
}