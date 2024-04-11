#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int>  mp;

    for(int i = 0; i < n; i++) {
        mp[s[i]]++;
    }

    if(mp.size() > 2) {
        int cur = 0;
        vector<string> a(k, "");
        for(auto p : mp) {
            while(p.s--) {
                a[cur++] = p.f;
                if(cur == k)
                    break;
            }

            mp[p.f] = p.s;

            if(cur == k)
                break;
        }

        for(auto p : mp) {
            for(int i = 0; i < p.s; i++)
                a[0] += p.f;
        }

        cout << max(a[0], a[k - 1]) << endl;
    } else {
        int cur = 0;
        int cnt = 0;
        char c1 = 0, c2 = 0;
        vector<string> a(k, "");
        for(auto p : mp) {
            if(p.s > 0) {
                cnt++;
                if(c1 == 0)
                    c1 = p.f;
                else if(c2 == 0)
                    c2 = p.f;

                while(p.s--) {
                    a[cur++] = p.f;
                    if(cur == k)
                        break;
                }

                mp[p.f] = p.s;

                if(cur == k)
                    break;
                }


        }

        for(auto p : mp)
            if(p.s != 0 && p.f != c1)
                c2 = p.f;

        if(c2 == 0) {
            int i = 0;

            while(mp[c1] > 0) {
                mp[c1]--;
                a[i] += c1;
                i = (i + 1) % k;
            }
        } if(mp[c1] == 0 && cnt == 1) {
            int i = 0;

            while(mp[c2] > 0) {
                mp[c2]--;
                a[i] += c2;
                i = (i + 1) % k;
            }
//            cout << "sdg" << endl;
        } else {
            for(int i = 0; i < mp[c1]; i++)
                a[0] += c1;
            for(int i = 0; i < mp[c2]; i++)
                a[0] += c2;

        }

        string mx = "";
        for(int i = 0; i < k; i++)
            mx = max(mx, a[i]);
        cout << mx << endl;
    }

    /*vector<string> a(k, "");
    int cur = 0;
    for(int i = 0; i < c.size(); i++) {
        if(c[i] > 0)
            while(c[i]--) {
                a[cur++] += char(i);
                if(cur == k)
                    break;
            }

        if(cur == k)
            break;
    }

//    if(a[0] != a[k - 1]) {
        for(int i = 0; i < c.size(); i++)
            for(int j = 0; j < c[i]; j++)
                a[0] += char(i);

        cout << max(a[k - 1] << endl;
        return;*/
//    }

//cout << "dg" << endl;

    /*int sum = n - k;
    for(int i = 0; i < c.size(); i++) {
        sum -= c[i];
//        cout << "sum " << sum << ' ' << i << ' ' << c[i] << endl;
        if(c[i] % k == 0) {
            for(int j = 0; j < k; j++)
                for(int l = 0; l < c[i] / k; l++)
                    a[j] += char(i);
        } else {
            while(c[i] >= k) {
                for(int j = 0; j < k; j++)
                    a[j] += char(i);
                c[i] -= k;
            }

            cout << "sum " << sum << endl;

            if(sum == 0) {
                for(int j = 0; j < c[i]; j++)
                    a[j] += char(i);
            } else {
                for(int j = i; j < c.size(); j++)
                    for(int l = 0; l < c[j]; l++)
                        a[0] += char(j);
            }

            break;
        }
    }

    string mx = a[0];
    for(int i = 0; i < k; i++)
        mx = max(mx, a[i]);
    cout << mx << endl;*/
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}