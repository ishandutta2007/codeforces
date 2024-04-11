#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int main(){
    int val[26];
    string s;
    for(int i = 0; i < 26; ++i){
        cin >> val[i];
    }
    cin >> s;
    long long sum[s.size() + 1];
    sum[0] = 0;
    vector<int> ch[26];
    for(int i = 1; i <= s.size(); ++i){
        sum[i] = sum[i - 1] + val[s[i - 1] - 'a'];
        ch[s[i - 1] - 'a'].push_back(i);
    }
    long long ans = 0;
    for(int i = 0; i < 26; ++i){
        map<long long, int> A;
        for(int j = 0; j < ch[i].size(); ++j){
            ans += A[sum[ch[i][j] - 1]];
            A[sum[ch[i][j]]]++;
        }
    }
    cout << ans;
    return 0;
}