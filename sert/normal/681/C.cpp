#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

priority_queue <int> q;
vector <string> ans;
string tmp, s;
int n, x;
bool m;

string its (int x) {
    if (x == 0) return "0";
    if (x < 0) {
        m = true;
        x = -x;
    } else {
        m = false;
    }
    tmp.clear();
    while (x > 0) {
        tmp += char('0' + x % 10);
        x /= 10;
    }
    if (m) tmp += '-';
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "removeMin") {
            if (q.empty())
                ans.push_back("insert 34");
            else
                q.pop();

            ans.push_back(s);
            continue;
        }

        if (s == "insert") {
            cin >> x;
            q.push(-x);
            ans.push_back(s + " " + its(x));
            continue;
        }

        if (s == "getMin") {
            cin >> x;
            while (true) {
                if (q.empty()) {
                    ans.push_back("insert " + its(x));
                    q.push(-x);
                    break;
                }
                if (q.top() < -x) {
                    ans.push_back("insert " + its(x));
                    q.push(-x);
                    break;
                }
                if (q.top() == -x)
                    break;
                q.pop();
                ans.push_back("removeMin");
            }
            ans.push_back("getMin " + its(x));
        }
    }

    cout << ans.size() << "\n";
    for (string t: ans) cout << t << "\n";

    return 0;
}