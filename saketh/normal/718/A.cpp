#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int INF = INT_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, T;
    string grade;
    cin >> N >> T >> grade;

    bool saw_dot = false;
    vector<int> rc(grade.size(), INF);

    int dot_inx;

    for (int i = grade.size() - 1; i >= 0; i--) {
        if (grade[i] == '.') {
            dot_inx = i;
            saw_dot = true;
            continue;
        }

        if (i + 1 == grade.size()) {
            // Can't round the last one
            continue;
        }

        int dig = grade[i + 1 + saw_dot] - '0';

        if (dig >= 5) {
            rc[i] = 1;
        } else if (dig == 4) {
            rc[i] = rc[i + 1 + saw_dot] + 1;
        }

        if (saw_dot) break;
    }

    int lo = 0;
    for (; lo < rc.size(); lo++) {
        if (rc[lo] <= T)
            break;
    }

    if (lo < rc.size()) {
        while (lo >= 0 && (grade[lo] == '.' || grade[lo] == '9'))
            lo--;
            
        grade = grade.substr(0, lo + 1);
        int pad = 0;

        if (grade.size() == 0) {
            grade = "1";
            pad = 1;
        }
        else {
            grade.back()++;
        }

        pad += dot_inx - grade.size();

        cout << grade;
        for (int i = 0; i < pad; i++)
            cout << "0";
        cout << endl;

    } else {
        cout << grade << "\n";
    }

    return 0;
}