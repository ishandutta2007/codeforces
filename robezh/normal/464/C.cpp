#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, mod = (int)1e9 + 7;
typedef long long ll;

string num;
int Q;
string s[N];
int len[10], val[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> num;
    cin >> Q;
    for(int i = 0; i < Q; i++) cin >> s[i];
    for(int i = 0; i < 10; i++) val[i] = i, len[i] = 10;

    for(int i = Q-1; i >= 0; i--){
        ll nlen = 1, nval = 0;
        for(int j = s[i].length()-1; j >= 3; j--){
            nval += 1LL * nlen * val[s[i][j]-'0'];
            nval %= mod;
            nlen *= len[s[i][j]-'0'];
            nlen %= mod;
        }
        len[s[i][0]-'0'] = (int)nlen;
        val[s[i][0]-'0'] = (int)nval;
    }
    //cout << len[2] << " " << val[2] << endl;
    ll res = 0, nlen = 1;
    for(int i = num.length()-1; i >= 0; i--){
        res += nlen * val[num[i]-'0'];
        res %= mod;
        nlen *= len[num[i]-'0'];
        nlen %= mod;
    }
    cout << res;

}