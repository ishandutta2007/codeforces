#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

vi kmp(vi s) {
    int n = s.size();
    vi pi(n);
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j += s[i] == s[j];
    }
    return pi;
}

bool match(vi A, vi B) {
    int m = B.size();
    B.push_back(-1);
    for(auto x : A)
        B.push_back(x);
    auto pi = kmp(B);
    for(int x : pi) {
        if(x == m) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi A, B;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x)
            A.push_back(x);
    }
    for(int i = 0; i< n; i++) {
        int x;
        cin >> x;
        if(x)
            B.push_back(x);
    }
    for(int i = 0; i < n - 1; i++)
        A.push_back(A[i]);
    cout << (match(A, B) ? "YES" : "NO") << '\n';
}