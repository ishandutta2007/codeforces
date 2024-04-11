#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int L, S, B, K;
    cin >> L >> S >> B >> K;

    vector<int> init(L);
    for (int i = 0; i < L; i++) {
        char c;
        cin >> c;
        init[i] = (c == '1');
    }

    L++;
    init.push_back(1);

    int cur_fit = 0;
    int cur_len = 0;
    for (int i = 0; i < L; i++) {
        if (init[i]) { 
            cur_fit += cur_len / B;
            cur_len = 0;
        } else {
            cur_len++;
        }
    }

    int kill = cur_fit - S + 1;

    vi shoot;

    cur_len = 0;
    for (int i = 0; i < L - 1; i++) {
        if (init[i]) {
            cur_len = 0;
        } else { 
            cur_len++;

            if (cur_len == B && kill > 0) {
                shoot.push_back(i);
                cur_len = 0;
                kill--;
            }
        }
    }

    cout << shoot.size() << "\n";
    for (int inx : shoot)
        cout << inx + 1 << " ";
    cout << endl;

    return 0;
}