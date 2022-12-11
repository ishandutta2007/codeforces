#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e5 + 2;
#define fr(i, n) for(int i = 0; i < n; i++)

int n, m;
int h1, h2;
int kz, kkz;
vector <int> f[1010];
vector <int> k[1010];
int ff[1001][1001];
int kk[1001][1001];


int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    fr(i, n){
        cin >> h1 >> h2;
        f[h2].push_back(h1);
        ff[h1][h2]++;
    }
    fr(i, m){
        cin >> h1 >> h2;
        k[h2].push_back(h1);
        kk[h1][h2]++;
    }

    fr(i, 1010){
        sort(f[i].begin(), f[i].end());
        sort(k[i].begin(), k[i].end());
    }

    int uk;

    fr(i, 1010){
        h1 = min(k[i].size(), f[i].size());
        if (h1 == 0) continue;
        h2 = f[i].size() - k[i].size();
        kz += h1;

        fr(j, 1001)
            kkz += min(ff[j][i], kk[j][i]);
    }

    cout << kz << " " << kkz;

    return 0;
}