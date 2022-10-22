#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 5e5 + 13;
const int INF = 2e9;

mt19937 rnd(time(0));

struct Exam {
    int s, f, c, ind;
    int left;

    Exam() {};
};

bool operator < (const Exam& a, const Exam& b) {
    if(a.f != b.f)
        return a.f < b.f;
    else if(a.s != b.s)
        return a.s < b.s;
    else
        return a.ind < b.ind;
}

bool cmp(const Exam& a, const Exam& b) {
    if(a.s != b.s)
        return a.s < b.s;
    else if(a.f != b.f)
        return a.f < b.f;
    else
        return a.ind < b.ind;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<Exam> a(n);
    vector<int> left(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f >> a[i].c;
        a[i].s--;
        a[i].f--;
        a[i].left = a[i].c;
        a[i].ind = i;
        left[i] = a[i].left;
    }

    sort(a.begin(), a.end(), cmp);

    set<Exam> st;
    vector<int> ans(m, -1);

    for(int i = 0; i < n; i++) {
        if(ans[a[i].f] != -1) {
            cout << -1;
            return 0;
        } else {
            ans[a[i].f] = n;
        }
    }

    int cur = 0;
    for(int i = 0; i < m; i++) {

        while(cur < n && a[cur].s <= i) {
            st.insert(a[cur++]);
        }

        if(!st.empty()) {
            if(st.begin()->f == i) {
                if(st.begin()->left > 0) {
                    cout << -1;
                    return 0;
                }
            } else if(ans[i] == -1) {
//                st.begin()->left--;
                left[st.begin()->ind]--;
                ans[i] = st.begin()->ind;
                if(left[st.begin()->ind] == 0)
                    st.erase(st.begin());
            }
        }
    }

    if(!st.empty()) {
        cout << -1;
        return 0;
    }

    for(auto an : ans)
        cout << an + 1 << ' ';
}