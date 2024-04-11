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

void fail() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const string shirts[6] = { "S", "M", "L", "XL", "XXL", "XXXL" };

    int avail[6];

    for (int i = 0; i < 6; i++)
        cin >> avail[i];

    stack<int> sing[6], doub[5];

    int N;
    cin >> N;
    vector<string> ans(N);

    for (int i = 0; i < N; i++) {
        string req;
        cin >> req;

        int comma = req.find(',');
        string size = (comma == string::npos) ? req : req.substr(0, comma);

        int inx = 0;
        for (int j = 0; j < 6; j++)
            if (shirts[j] == size)
                inx = j;

        if (comma == string::npos) sing[inx].push(i);
        else doub[inx].push(i);
    }

    for (int i = 0; i < 6; i++) {
        while (sing[i].size()) {
            if (!avail[i]) fail();
            avail[i]--;
            ans[sing[i].top()] = shirts[i];
            sing[i].pop();
        }
    }

    for (int i = 0; i < 5; i++) {
        while (doub[i].size()) {
            if (avail[i]) {
                avail[i]--;
                ans[doub[i].top()] = shirts[i];
                doub[i].pop();
            } else if (avail[i+1]) {
                avail[i+1]--;
                ans[doub[i].top()] = shirts[i+1];
                doub[i].pop();
            } else
                fail();
        }
    }

    cout << "YES\n";
    for (string r : ans)
        cout << r << "\n";

    return 0;
}