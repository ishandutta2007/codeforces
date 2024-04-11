#include <bits/stdc++.h>
using namespace std;

string s[1500];
unordered_multiset<string> mst;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        mst.insert(s[i]);
    }
//        for (auto p : mp) {
//            string match;
//            for (int j=0; j<k; j++) {
//                if (p.first.first[j] == p.first.second[j])
//                    match += p.first.first[j];
//                else {
//                    unordered_set<char> st{'S', 'E', 'T'};
//                    st.erase(p.first.first[j]);
//                    st.erase(p.first.second[j]);
//                    match += *st.begin();
//                }
//                if (s[i][j] != match[j])
//                    break;
//            }
//            if (s[i] == match)
//                ret += p.second;
//        }
//        for (int j=0; j<i; j++) {
//            string a = s[i], b = s[j];
//            if (a > b)
//                swap(a, b);
//            mp[make_pair(a, b)]++;
//        }
//    }

    long long ret = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            if (i == j)
                continue;
            string match(k, ' ');
            for (int kk=0; kk<k; kk++) {
                if (s[i][kk] == s[j][kk])
                    match[kk] = s[i][kk];
                else {
//                    unordered_set<char> st{'S', 'E', 'T'};
//                    st.erase(s[i][kk]);
//                    st.erase(s[j][kk]);
//                    match[kk] = *st.begin();
                    if (s[i][kk] != 'S' && s[j][kk] != 'S')
                        match[kk] = 'S';
                    else if (s[i][kk] != 'E' && s[j][kk] != 'E')
                        match[kk] = 'E';
                    else
                        match[kk] = 'T';
                }
            }
            ret += mst.count(match) - (match == s[i]) - (match == s[j]);
//            cerr << ret << "\n";
            //cout << "DOING SOMETHING " << i << " " << j << "\n";
        }

    cout << ret / 6 << "\n";

    return 0;
}