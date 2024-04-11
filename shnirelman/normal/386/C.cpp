#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 3e5 + 13;
const int INF = 1e9;
const int A = 26;

int a[N];
int lf[N][A];
int lst[A];
li ans[A];

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = s[i] - 'a';

    for(int i = 0; i < A; i++)
        lst[i] = -1;

    for(int i = 0; i < n; i++) {
        lst[a[i]] = i;
        for(int j = 0; j < A; j++)
            lf[i][j] = lst[j];

        sort(lf[i], lf[i] + A);

        for(int j = A - 2; j >= -1; j--) {
//            cout << i << ' ' << j << ' ' << lf[i][j] << ' ' << A - j - 2 << endl;
            if(j == -1 || lf[i][j] == -1) {
                ans[A - j - 2] += lf[i][j + 1] + 1;
                break;
            } else {
                ans[A - j - 2] += lf[i][j + 1] - lf[i][j];
            }
        }
    }

    for(int i = 0; i <= A; i++) {
        if(i == A || ans[i] == 0) {
            cout << i << endl;
            for(int j = 0; j < i; j++)
                cout << ans[j] << endl;
            break;
        }

//        if(i == A - 1) {
//            cout << A << endl;;
//        }
    }
}