#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int prime[5000];

void sieve() {
    for(int p = 2; p < 5000; p++) {
        if(prime[p]) continue;
        for(int q = 2*p; q < 5000; q += p)
            prime[q] = p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n;
    cin >> n;
    int edg = n;
    vector<ii> res;
    int pt = 1;
    for(int i = 1; i <= n - 1; i++)
        res.push_back({i, i + 1});
    res.push_back({n, 1});
    while(prime[edg]) {
        res.push_back({pt, pt + n/2});
        pt++;
        edg++;
    }
    cout << edg << '\n';
    for(auto p : res)
        cout << p.first << " " << p.second << '\n';
}