#include <bits/stdc++.h>

#define MAXN 200000

using namespace std;

vector<int> maxdig(MAXN);
vector<int> maxint(MAXN);

void initmaxint() {
    maxint[1] = 4;
    int deg2 = 8;
    for (int i = 2; i < MAXN; i++) {
        maxint[i] = maxint[i-1] + 1;
        if (maxint[i] + 1 == deg2) {
            maxint[i]++;
            deg2 *= 2;
        }
    }
}

void initmaxdig() {
    maxdig[1] = 3;
    int deg2 = 8;
    for (int i = 2; i < MAXN; i++) {
        maxdig[i] = maxdig[i-1];
        if (maxdig[i] + i + 1 == deg2) {
            maxdig[i]++;
            deg2 *= 2;
        }
    }
}

int stringtoint(string s) {
    int rez = 0;
    int ind = 0;
    while (ind < s.size()) {
        rez *= 2;
        if (s[ind] == '1')
            rez++;
        ind++;
    }
    return rez;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string s;
    cin >> t;
    int len;
    initmaxdig();
    initmaxint();
    for (int qq = 0; qq < t; qq++) {
        cin >> s;
        len = s.size();
        int ans = 0;
        if (s[0] == '1') {
            ans++;
            if (len > 1 && s[1] == '0')
                ans++;
        }
        if (len > 1 && s[1] == '1')
            ans++;
        for (int i = 2; i < len; i++) {
            if (s[i] == '1') {
                ans++;
                if (s[i-1] == '1' && s[i-2] == '0')
                    ans++;
            }
            else if (s[i-1] == '1')
                ans++;

        }
        //cout << ans << ", ";
        s += "-";
        int ind0, ind1, indcur;
        int delta;
        indcur = 0;
        while (indcur < len) {
            while (s[indcur] == '1')
                indcur++;
            if (s[indcur] == '-')
                break;
            ind0 = indcur;
            while(s[indcur] == '0')
                indcur++;
            if (s[indcur] == '-')
                break;
            ind1 = indcur;
            delta = 1;
            while (s[ind1 + delta - 1] != '-' && delta < maxdig[ind1 - ind0]) {
                if (delta > 2)
                    ans++;
                delta++;
            }
            if (s[ind1 + delta - 1] != '-') {
                //cout << s.substr(ind1, delta) << ", " << stringtoint(s.substr(ind1, delta)) << "|";
                if (stringtoint(s.substr(ind1, delta)) <=  maxint[ind1 - ind0])
                    ans++;
            }
            //cout << ind0 << " - " << ind1 << " - " << delta << "(" << ans << "); ";
        }
        cout << ans << '\n';
    }
    return 0;
}