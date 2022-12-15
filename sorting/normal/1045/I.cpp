#include <bits/stdc++.h>

using namespace std;

int get_mask(const string &s){
    static int cnt[26];
    for(int i = 0; i < 26; ++i)
        cnt[i] = 0;
    for(char c: s)
        cnt[c - 'a']++;

    int answer = 0;
    for(int i = 0; i < 26; ++i)
        answer += (cnt[i] & 1) ? (1 << i) : 0;
    return answer;
}

const int k_N = 1e5 + 7;

unordered_map<int, int> cnt;
int mask[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];

    for(int i = 0; i < n; ++i){
        mask[i] = get_mask(s[i]);
        cnt[mask[i]]++;
    }

    long long answer = 0;
    for(int i = 0; i < n; ++i){
        answer += cnt[mask[i]] - 1;
        for(int j = 0; j < 26; ++j)
            answer += cnt[mask[i] ^ (1 << j)]; 
    }

    answer /= 2;
    cout << answer << "\n";
}