#include <bits/stdc++.h>

using namespace std;

const int k_Mask = (1 << 24);

int cnt[k_Mask];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        int mask = k_Mask - 1;
        for(char c: s){
            int x = (c - 'a');
            if(mask & (1 << x))
                mask ^= (1 << x);
        }

        cnt[mask]++;
    }

    for(int bit = 1; bit < k_Mask; bit <<= 1)
        for(int mask = 0; mask < k_Mask; ++mask)
            if(!(mask & bit))
                cnt[mask] += cnt[(mask ^ bit)];

    int answer = 0;
    for(int mask = 0; mask < k_Mask; ++mask){
        cnt[mask] = n - cnt[mask];
        answer ^= cnt[mask] * cnt[mask];
    }

    cout << answer << "\n";

    return 0;
}