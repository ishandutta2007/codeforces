#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

ll val[128];
bool auc[128];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < M; i++) {
        int idx;
        cin >> idx;
        auc[idx-1] = true;
    } 

    ll score = 0;

    vector <ll> auctions;
    for (int i = 0; i < N; i++) {
        if(!auc[i]) score += val[i];
        else auctions.push_back(val[i]);
    }

    sort(auctions.begin(), auctions.end(), std::greater<ll>());

    for (ll v : auctions) {
        if(v > score) score += v;
        else score *= 2;
    }

    cout << score << endl;
}