#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int N = 3e5 + 2;
#define fr(i, n) for(int i = 0; i < n; i++)

int n, m, a[N], sml[N], l, r, ss[N], sf[N], s[N], h[N];

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> m;

    int len = 0;

    fr(i, n) cin >> a[i];
    for(int i = 1; i < n - 1; i++){
        if (a[i] < min(a[i - 1], a[i + 1]))
            sml[i] = 1;
        if (a[i] == a[i - 1] && a[i] < a[i + 1]){
            s[len] = i;
            h[len++] = 1;
        }
        if (a[i] == a[i + 1] && a[i] < a[i - 1]){
            s[len] = i;
            h[len++] = -1;
        }
    }

    fr(i, len - 1){
        if (h[i] == -1 && h[i + 1] == 1){
            ss[s[i]] = 1;
            sf[s[i + 1]] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        sml[i] += sml[i - 1];
        ss[i] += ss[i - 1];
        sf[i] += sf[i - 1];
    }

    fr(i, m){
        cin >> l >> r;
        if (r - l < 2){
            cout << "Yes\n";
            continue;
        }
        r--; l--;

        if (ss[r - 1] != ss[l] && sf[r - 1] != sf[l]){
            cout << "No\n";
            continue;
        }

        if (sml[r - 1] != sml[l])
            cout << "No\n";
        else
            cout << "Yes\n";
    }


    return 0;
}