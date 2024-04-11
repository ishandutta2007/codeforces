#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef int ll;

const ll N = 2014;

int f[N], s[N], t[N];
string s1, s2;
int n, kol, d, n1, n2;
map <string, int> m;
set <pair<int, int> > st;
set <pair<int, int> > :: iterator it;
string name[N];

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (m.find(s1) == m.end()) {
            name[kol] = s1;
            m[s1] = kol++;
        }
        if (m.find(s2) == m.end()) {
            name[kol] = s2;
            m[s2] = kol++;
        }
        cin >> t[i];
        f[i] = m[s1];
        s[i] = m[s2];
        //cerr << s[i] << " " << f[i] << "\n";
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (s[i] == f[j] && f[i] == s[j] && t[j] - t[i] <= d && t[j] > t[i])
                st.insert(make_pair(min(s[i], f[i]), max(s[i], f[i])));
        }

    printf("%d\n", st.size());
    for (it = st.begin(); it != st.end(); it++) {
        s1 = name[(*it).first];
        s2 = name[(*it).second];
        printf("%s %s\n", s1.c_str(), s2.c_str());
    }
    return 0;
}