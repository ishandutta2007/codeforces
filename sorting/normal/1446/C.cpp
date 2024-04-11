#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 3;

int n, a[N];
bool rem[N];

vector<array<int, 3>> st;

void add(int idx, int x, int bit){
    st[idx][0]++;
    if(bit == -1) return;

    int w = (x >> bit) & 1;
    if(st[idx][w + 1] == -1){
        st[idx][w + 1] = st.size();
        st.push_back({0, -1, -1});
    }

    add(st[idx][w + 1], x, bit - 1);
}

int solve(int idx, int bit){
    if(bit == -1) return 0;
    if(st[idx][1] == -1) return solve(st[idx][2], bit - 1);
    if(st[idx][2] == -1) return solve(st[idx][1], bit - 1);

    return min(solve(st[idx][1], bit - 1) + max(0, st[st[idx][2]][0] - 1), solve(st[idx][2], bit - 1) + max(0, st[st[idx][1]][0] - 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    st.push_back({0, -1, -1});
    for(int i = 0; i < n; ++i)
        add(0, a[i], 29);

    cout << solve(0, 29) << '\n';
}