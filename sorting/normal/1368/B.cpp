#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;
    cin >> k;

    string s = "codeforces";
    for(int i = 0; i < 10; ++i)
        cnt[i] = 1;

    if(k == 1){
        cout << s << "\n";
        return 0;
    }

    long long curr = 1, idx = 0;
    while(curr < k){
        curr /= cnt[idx];
        cnt[idx]++;
        curr *= cnt[idx];

        idx++;
        idx %= 10;
    }

    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < cnt[i]; ++j)
            cout << s[i];
    cout << "\n";
}