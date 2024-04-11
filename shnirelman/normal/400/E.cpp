#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 19;

li f(int d) {
    return (d <= 0 ? 0 :d * 1ll * (d + 1) / 2);
}

/*
3 1
1 1 1
2 0
*/

vector<li> get(int n, int m, vector<int> a, vector<pii> b) {
    set<pii> st;
    st.insert({n, n});
    li cur = 0;
    for(int i = 0; i < n; ) {
        if(a[i] == 0) {
            st.insert({i, i});
            i++;
            continue;
        }

        int j = i;
        while(j < n && a[j] == 1)
            j++;

//        cout << i << ' ' << j << endl;

        st.insert({i, j});
        cur += f(j - i);

        i = j + 1;
    }
    /*vector<int> lf(n + 1, -1), rg(n + 1, n);
    for(int i = n - 2; i >= 0; i--) {
        rg[i] = (a[i + 1] == 0 ? i + 1 : rg[i + 1]);
    }

    for(int i = 1; i < n; i++) {
        lf[i] = (a[i - 1] == 0 ? i - 1 : lf[i - 1]);
    }




    for(int i = 0; i < n; ) {
        int r = rg[i];
        int l = lf[r];

        st.insert({l, r});

//        cout << i << ' ' << l << ' ' << r << endl;

        cur += f(r - l - 1);
        i = r;
    }*/

//    cout  << cur << endl;

    vector<li> res(m);

    for(int i = 0; i < m; i++) {
//        cout << "sg " << i << ' ' << cur << endl;
//
//        for(auto p : st)
//            cout << p.f<< ";" << p.s << ' ';
//        cout << endl;
        int j = b[i].f;
        if(b[i].s == a[j]) {
            res[i] = cur;
            continue;
        }

        a[j] = b[i].s;

        if(a[j] == 0) {
            auto it = st.upper_bound({j, n});
            it--;

            int l = it->f, r = it->s;

            st.erase(it);

            cur -= f(r - l);
            cur += f(j - l) + f(r - j - 1);

            st.insert({l, j});
            st.insert({j + 1, r});
//            cout << j << ' ' << l << ' ' << r << ' ' << endl;


        } else {
            auto it2 = st.lower_bound({j, n});
            auto it1 = it2;
            it1--;

            int l = it1->f, r = it2->s;

            st.erase(it1);
            st.erase(it2);

            cur += f(r - l);
            cur -= f(j - l) + f(r - j - 1);
//cout << "sf" << endl;
//            cout << l << ' ' << r << endl;
            st.insert({l, r});
//cout << j << ' ' << l << ' ' << r << ' ' << endl;
//cout << "sf" << endl;
        }
//cout << "sf" << endl;
        res[i] = cur;
//        cout << "sf" << endl;
    }

    return res;
}

/*
3 1
1 1 1
1 1

3 1
0 0 0
2 1

*/

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<pii> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i].f >> b[i].s;
        b[i].f--;
    }

    vector<li> ans(m, 0);

    for(int i = 0; i < 19; i++) {
//        cout << i << endl;
        vector<int> a1(n);
        for(int j = 0; j < n; j++)
            a1[j] = ((a[j] & (1 << i)) >> i);

        vector<pii> b1(m);
        for(int j = 0; j < m; j++) {
            b1[j] = {b[j].f, ((b[j].s & (1 << i)) >> i)};
        }

        vector<li> res = get(n, m, a1, b1);
        for(int j = 0; j < m; j++) {
//            cout << "sg shh " << j << ' ' << res[j] << endl;
            ans[j] += (res[j] << i);
        }
    }

    for(auto x : ans)
        cout << x << '\n';
}