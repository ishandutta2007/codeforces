#include <bits/stdc++.h>

using namespace std;

const int A = 26;

int p[A];
bool is[A];

int getP(int x) {
    if(x == p[x])
        return x;
    else
        return p[x] = getP(p[x]);
}

void unit(int x, int y) {
     x = getP(x);
     y = getP(y);

     if(x == y)
        return;

     p[x] = y;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < A; i++)
        p[i] = i;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        vector<bool> b(A, false);
        for(int j = 0; j < s.length(); j++) {
            b[s[j] - 'a'] = true;
            is[s[j] - 'a'] = true;
        }


        for(int j = 0; j < A; j++)
            if(b[j])
                for(int l = 0; l < A; l++)
                    if(b[l])
                        unit(l, j);
    }

    set<int> s;
    for(int i = 0; i < A; i++)
        if(is[i])
            s.insert(getP(i));
    cout << s.size();
}