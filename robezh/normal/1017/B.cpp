#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s1,s2;
int cnt[2][2];

int main(){
    cin >> n >> s1 >> s2;
    for(int i = 0; i < n; i++){
        cnt[s1[i]-'0'][s2[i]-'0']++;
    }
    ll res = 0;
    res += 1LL * (cnt[0][1] + cnt[0][0]) * (cnt[1][0] + cnt[1][1]);
    res -= 1LL * cnt[0][1] * cnt[1][1];
    cout << res << endl;
}