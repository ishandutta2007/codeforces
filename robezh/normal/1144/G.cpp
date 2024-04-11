#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, INF = (int)1e9;

int n;
int num[N], res[N];

int get(int i) {
    if(i == -1) return -INF;
    if(i == -2) return INF;
    return num[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    vector<int> L, R;
    for(int i = 0; i < n; i++) {
        bool gl = L.empty() || num[i] > L.back();
        bool gr = R.empty() || num[i] < R.back();
        if(gl && gr) {
            if(num[i+1] >= num[i]) L.push_back(num[i]);
            else R.push_back(num[i]), res[i] = true;
        }
        else if(gl) L.push_back(num[i]);
        else if(gr) R.push_back(num[i]), res[i] = true;
        else return !printf("NO");
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << res[i] << " ";

}