#include <bits/stdc++.h>

using namespace std;

int cnt[20 + 3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        for(int bit = 0; bit < 20; ++bit)
            cnt[bit] += (bool)(a[i] & (1 << bit));
    }

    long long answer = 0;
    for(int i = 0; i < n; ++i){
        long long curr = 0;
        for(int bit = 0; bit < 20; ++bit)
            if(cnt[bit] > i)
                curr += (1 << bit);

        answer += curr * curr;
    }

    cout << answer << "\n";
}