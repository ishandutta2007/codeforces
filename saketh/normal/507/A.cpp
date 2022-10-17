#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K;
int days[128];
int ord[128];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> days[i];
        ord[i] = i;
    }

    sort(ord, ord+N, [](int i, int j){ return days[i] < days[j]; });

    vector<int> res;

    for (int i = 0; i < N; i++) {
        if(K >= days[ord[i]]){
            res.push_back(ord[i]);
            K -= days[ord[i]];
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for(int v : res) cout << v+1 << " ";
    cout << endl;
}