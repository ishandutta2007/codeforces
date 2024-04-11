#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;


struct SuffixArray {
    vi sa, lcp, rank;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
//        string s = init;
        /*             1- */
        vector <int> head;
        /*color[i] -  ,   i- */
        vector <int> color;
        /* ,   color,     */
        vector <int> colorSub;
        vector <int> suffArraySub;
        /*256 -   */
        head.assign(max((int)s.size(), 256), 0);
        sa.resize(s.size());
        color.resize(s.size());
        colorSub.resize(s.size());
        suffArraySub.resize(s.size());

        /*     */
        for (int i = 0; i < s.size(); ++i) {
            ++head[s[i]];
        }
        for (int i = 1; i < 256; ++i) {
            head[i] += head[i - 1];
        }
        for (int i = 255; i > 0; --i) {
            head[i] = head[i - 1];
        }
        head[0] = 0;
        for (int i = 0; i < s.size(); ++i) {
            sa[head[s[i]]] = i;
            ++head[s[i]];
        }
        /* suffArray     */

        /*   ,  head  ,   */
        int numberOfClasses = 1;
        head[0] = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[sa[i - 1]] != s[sa[i]]) {
                ++numberOfClasses;
                head[numberOfClasses - 1] = i;
            }
            color[sa[i]] = numberOfClasses - 1;
        }

        /**/
        for (int k = 1; k < s.size(); k *= 2) {
            /*    2*k*/

            for (int i = 0; i < s.size(); ++i) {
                int firstPartBeginning = sa[i] - k;
                if (firstPartBeginning < 0) {
                    firstPartBeginning += s.size();
                }
                suffArraySub[head[color[firstPartBeginning]]] = firstPartBeginning;
                ++head[color[firstPartBeginning]];
            }
            sa = suffArraySub;

            /* color  head*/
            int secondPartBeginning;
            pair <int, int> prevSuffClasses, curSuffClasses;
            curSuffClasses = make_pair(-1, 0);
            numberOfClasses = 0;

            for (int i = 0; i < s.size(); ++i) {
                prevSuffClasses = curSuffClasses;

                secondPartBeginning = sa[i] + k;
                if (secondPartBeginning >= s.size()) {
                    secondPartBeginning -= s.size();
                }
                curSuffClasses = make_pair(color[sa[i]], color[secondPartBeginning]);

                if (curSuffClasses != prevSuffClasses) {
                    ++numberOfClasses;
                    head[numberOfClasses - 1] = i;
                }
                colorSub[sa[i]] = numberOfClasses - 1;
            }

            color = colorSub;

            /*      ->  suffArray  */
            if (numberOfClasses == s.size())
                break;
        }
        rank.resize(sz(s));
        rep(i,0,sz(s)) rank[sa[i]] = i;
//        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
//            for (k && k--, j = sa[rank[i] - 1];
//                    s[i + k] == s[j + k]; k++);
    }
};

const int N = (int)2e6 + 50;

int ps[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c = 0;
    string str;
    cin >> str;
    int n = str.length();
    str += str;
    SuffixArray sa(str);
    rep(i, 0, 2 * n) {
        c += (str[i] == '(' ? 1 : -1);
        ps[i] = c;
    }
    c = ps[n - 1];

    int th = (c < 0 ? c : 0);
    deque<pii> que;
    rep(i, 0, n) {
        while(!que.empty() && ps[i] <= que.front().first) que.pop_front();
        que.push_front({ps[i], i});
    }
    int mn_rot = -1;
    rep(i, 0, n) {
        while(que.back().second < i) que.pop_back();
        int mn = que.back().first - (i ? ps[i - 1] : 0);
        if(mn >= th) {
            if(mn_rot == -1 || sa.rank[i] < sa.rank[mn_rot]) mn_rot = i;
        }
        while(!que.empty() && ps[i + n] <= que.front().first) que.pop_front();
        que.push_front({ps[i + n], i + n});
    }
    string rs = str.substr(0, n);
    rotate(rs.begin(), rs.begin() + mn_rot, rs.end());
    if(c >= 0) {
        string res = rs;
        while(c--) res.push_back(')');
        cout << res << '\n';
    } else {
        string res;
        c = -c;
        while(c--) res.push_back('(');
        res += rs;
        cout << res << '\n';
    }


}