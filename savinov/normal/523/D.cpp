#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int whr(int k, const string& s){
    int n = s.length();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++){
        p[i] = p[i - 1];
        while (p[i] > 0 && s[p[i]] != s[i])
            p[i] = p[p[i] - 1];
        if (s[i] == s[p[i]])
            p[i]++;
        if (p[i] == k)
            return i - k;
    }
    return -1;
}

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> s(n), m(n);
    for (int i = 0; i < n; i++)
        cin >> s[i] >> m[i];
    multiset<long long> S;
    for (int i = 0; i < k; i++)
        S.insert(0);
    for (int i = 0; i < n; i++){
        if (*(S.begin()) <= s[i]){
            cout << s[i] + m[i] << "\n";
            S.erase(S.begin());
            S.insert(s[i] + m[i]);
        } else {
            long long tmp = *(S.begin());
            cout << tmp + m[i] << "\n";
            S.erase(S.begin());
            S.insert(tmp + m[i]);
        }
    }

    return 0;
}