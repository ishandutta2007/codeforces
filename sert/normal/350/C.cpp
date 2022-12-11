#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

vector <pair <ll, ll> > ul, ur, dl, dr;
vector<ll> ox0;
vector<ll> ox1;
vector<ll> oy0;
vector<ll> oy1;
ll ans, n;
pair<ll, ll> h;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n) {
        cin >> h.ff >> h.ss;
        if (h.ff == 0)
            if (h.ss > 0)
                ox1.pb(h.ss);
            else
                ox0.pb(-h.ss);
        if (h.ss == 0)
            if (h.ff > 0)
                oy1.pb(h.ff);
            else
                oy0.pb(-h.ff);
        if (h.ff * h.ss == 0) ans += 4;
        else {
            ans += 6;
            if (h.ff > 0 && h.ss > 0)
                ur.pb(h);
            if (h.ff > 0 && h.ss < 0)
                dr.pb(mp(h.ff, -h.ss));
            if (h.ff < 0 && h.ss > 0)
                ul.pb(mp(-h.ff, h.ss));
            if (h.ff < 0 && h.ss < 0)
                dl.pb(mp(-h.ff, -h.ss));
        }
    }

    cout << ans << "\n";

    sort(ox0.begin(), ox0.end());
    sort(ox1.begin(), ox1.end());
    sort(oy0.begin(), oy0.end());
    sort(oy1.begin(), oy1.end());
    sort(ul.begin(), ul.end());
    sort(ur.begin(), ur.end());
    sort(dl.begin(), dl.end());
    sort(dr.begin(), dr.end());

    fr(i, ox1.size()) {
        cout << "1 " << ox1[i] << " U\n";
        cout << "2\n";
        cout << "1 " << ox1[i] << " D\n";
        cout << "3\n";
    }

    fr(i, ox0.size()) {
        cout << "1 " << ox0[i] << " D\n";
        cout << "2\n";
        cout << "1 " << ox0[i] << " U\n";
        cout << "3\n";
    }

    fr(i, oy1.size()) {
        cout << "1 " << oy1[i] << " R\n";
        cout << "2\n";
        cout << "1 " << oy1[i] << " L\n";
        cout << "3\n";
    }

    fr(i, oy0.size()) {
        cout << "1 " << oy0[i] << " L\n";
        cout << "2\n";
        cout << "1 " << oy0[i] << " R\n";
        cout << "3\n";
    }

    fr(i, ul.size()) {
        cout << "1 " << ul[i].ss << " U\n";
        cout << "1 " << ul[i].ff << " L\n";
        cout << "2\n";
        cout << "1 " << ul[i].ff << " R\n";
        cout << "1 " << ul[i].ss << " D\n";
        cout << "3\n";
    }

    fr(i, ur.size()) {
        cout << "1 " << ur[i].ss << " U\n";
        cout << "1 " << ur[i].ff << " R\n";
        cout << "2\n";
        cout << "1 " << ur[i].ff << " L\n";
        cout << "1 " << ur[i].ss << " D\n";
        cout << "3\n";
    }

    fr(i, dl.size()) {
        cout << "1 " << dl[i].ss << " D\n";
        cout << "1 " << dl[i].ff << " L\n";
        cout << "2\n";
        cout << "1 " << dl[i].ff << " R\n";
        cout << "1 " << dl[i].ss << " U\n";
        cout << "3\n";
    }

    fr(i, dr.size()) {
        cout << "1 " << dr[i].ss << " D\n";
        cout << "1 " << dr[i].ff << " R\n";
        cout << "2\n";
        cout << "1 " << dr[i].ff << " L\n";
        cout << "1 " << dr[i].ss << " U\n";
        cout << "3\n";
    }

    return 0;
}