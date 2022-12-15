#include <bits/stdc++.h>

using namespace std;

const int k_N = 3e5 + 3;
const int k_Bits = 31;

int n;
int a[k_N];
long long sum[2][k_Bits];

void solve(const vector<int> &pos, int bit){
    if(bit == -1) return;
    if(pos.empty()) return;

    vector<int> new_pos[2];
    for(int i = 0; i < pos.size(); ++i){
        bool b = (a[pos[i]] & (1 << bit));
        if(b)
            sum[1][bit] += new_pos[0].size();
        else
            sum[0][bit] += new_pos[1].size();
        new_pos[b].push_back(pos[i]);
    } 

    solve(new_pos[0], bit - 1);
    solve(new_pos[1], bit - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> pos(n);
    for(int i = 0; i < n; ++i)
        pos[i] = i;

    solve(pos, k_Bits - 1);

    int x = 0;
    long long ans = 0;
    for(int i = 0; i < k_Bits; ++i){
        //cout << sum[0][i] << " - " << sum[1][i] << endl;
        if(sum[1][i] < sum[0][i])
            x += (1 << i);
        ans += min(sum[0][i], sum[1][i]);
    }

    cout << ans << " " << x << "\n";
}