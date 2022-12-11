#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

string delshit(string s) {
    string ans;
    for (char ch: s) {
        if ('a' <= ch && ch <= 'z')
            ans.push_back(ch);
        if ('A' <= ch && ch <= 'Z')
            ans.push_back(ch - 'A' + 'a');
    }
    return ans;
}


int main() {
    init();
    string a, b, c, d;
    int n;
    cin >> a >> b >> c >> n;
    a = delshit(a);
    b = delshit(b);
    c = delshit(c);
    while (n--) {
        cin >> d;
        d = delshit(d);
        if (d == a + b + c || d == a + c + b || d == b + a + c || d == b + c + a || d == c + a + b || d == c + b + a)
            cout << "ACC\n";
        else
            cout << "WA\n";
    }


    return 0;
}