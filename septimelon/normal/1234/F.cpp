#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

int couons(int x) {
    int rez = 0;
    while (x > 0) {
        ++rez;
        x = (x & (x - 1));
    }
    return rez;
}

int settoint(const set<char>& setc) {
    int rez = 0;
    for (char c = 'a'; c <= 't'; ++c) {
        if (setc.count(c) == 1) {
            rez += (1 << (c - 'a'));
        }
    }
    return rez;
}

int revint(int sint) {
    return (1 << 20) - 1 - sint;
}

int getiml(int isetc, vector<int>& vle) {
    if (vle[isetc] >= 0) {
        return vle[isetc];
    }
    
    int curi = isetc;
    int ma = 0;
    for (int i = 1; i < (1 << 20); i *= 2) {
        if ((curi | i) == curi) {
            curi -= i;
            int ca = getiml(curi, vle);
            ma = max(ma, ca);
            curi += i;
        }
    }
    vle[isetc] = ma;
    return ma;
}

/*set<char> revs(const set<char>& setc) {
    set<char> rez;
    for (char c = 'a'; c <= 't'; ++c) {
        if (setc.count(c) == 0) {
            rez.insert(c);
        }
    }
    return rez;
}

int getml(const set<char>& setc, map<set<char>, int>& mle) {
    if (mle.count(setc) > 0) {
        return mle[setc];
    }
    if (setc.size() == 0) {
        return 0;
    }
    
    set<char> curs = setc;
    int ma = 0;
    for (char c : setc) {
        curs.erase(c);
        int ca = getml(curs, mle);
        ma = max(ma, ca);
        curs.insert(c);
    }
    mle[setc] = ma;
    return ma;
}*/

void solve() {
    string s;
    cin >> s;
    vector<int> vle(2000000, -1);
    vle[0] = 0;
    map<set<char>, int> mle;
    
    int curs;
    //set<char> curs;
    //set<set<char>> sets;
    for (int i = 0; i < s.size(); ++i) {
        curs = 0;
        for (int j = i; j < s.size(); ++j) {
            if ((curs | (1 << (s[j] - 'a'))) == curs) {
                break;
            }
            curs += (1 << (s[j] - 'a'));
            vle[curs] = couons(curs);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << 20); ++i) {
        if (vle[i] != couons(i)) {
            continue;
        }
        int rset = revint(i);
        ans = max(ans, vle[i] + getiml(rset, vle));
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}