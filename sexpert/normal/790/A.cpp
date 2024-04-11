#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string gen(int x) {
    string res = "A";
    if(x < 26)
        res += ('a' + x);
    else {
        res += 'a';
        x -= 26;
        res += ('a' + x);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> name(n);
    int d = 0;
    for(int i = 0; i < k - 1; i++)
        name[i] = gen(d++);
    for(int i = k - 1; i < n; i++) {
        string eff;
        cin >> eff;
        if(eff == "NO")
            name[i] = name[i - k + 1];
        else
            name[i] = gen(d++);
    }
    for(int i = 0; i < n; i++)
        cout << name[i] << ' ';
    cout << '\n';
}