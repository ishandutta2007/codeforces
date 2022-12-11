#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

typedef long long ll;

#define fr(i, n) for(int i = 0; i < n; i++)
const int N = 1e6 + 7;
const ll p = 503;
const ll md = 1e9 + 9;

string s;
string w1, w2;
ll h1, h2, ho1, ho2;
ll h[N];
ll f1 = 1000000, f2 = 1000000, l1 = -1000000, l2 = -1000000;
ll st[N];
ll hsh;
bool fw, bw;

int main()
{
    //freopen("a.in", "r", stdin);

    cin >> s;
    h[0] = 0;
    for(int i = 1; i <= s.length(); i++)
        h[i] = (h[i - 1] * p + s[i - 1] - 'a' + 1) % md;

    st[0] = 1;
    fr(i, 100002)
        st[i + 1] = (st[i] * p) % md;

    cin >> w1;
    cin >> w2;

    fr(i, w1.length())
        h1 = (h1 * p + w1[i] - 'a' + 1) % md;
    fr(i, w2.length())
        h2 = (h2 * p + w2[i] - 'a' + 1) % md;
    fr(i, w1.length())
        ho1 = (ho1 * p + w1[w1.length() - i - 1] - 'a' + 1) % md;
    fr(i, w2.length())
        ho2 = (ho2 * p + w2[w2.length() - i - 1] - 'a' + 1) % md;

    for(int i = 1; i <= s.length() - w1.length() + 1; i++){
        hsh = (h[i + w1.length() - 1] - (h[i - 1] * st[w1.length()]) % md + md) % md;
        if (hsh == h1){
            if (f1 == 1000000) f1 = i;
        }
        if (hsh == ho1)
            l1 = i;
    }

    for(int i = 1; i <= s.length() - w2.length() + 1; i++){
        hsh = (h[i + w2.length() - 1] - (h[i - 1] * st[w2.length()]) % md + md) % md;
        if (hsh == ho2){
            if (f2 == 1000000) f2 = i;
        }
        if (hsh == h2)
            l2 = i;
    }

    if (f1 + w1.length() <= l2)
        fw = true;
    if (f2 + w2.length() <= l1)
        bw = true;

    if (fw)
        if (bw)
            cout << "both";
        else
            cout << "forward";
    else
        if (bw)
            cout << "backward";
        else
            cout << "fantasy";


    return 0;
}