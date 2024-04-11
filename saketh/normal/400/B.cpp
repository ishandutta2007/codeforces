#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
vector<int> dist;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        int G = str.find('G');
        int S = str.find('S');

        if ( G > S) { cout << -1 << endl; return 0; }
        dist.push_back(S - G);
    }

    sort(dist.begin(), dist.end());
    cout << unique(dist.begin(), dist.end()) - dist.begin() << endl;
}