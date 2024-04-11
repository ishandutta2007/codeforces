#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, mod = 998244353;
typedef long long ll;

string s;
string sl, sr;
ll psum[2][N], res[2][N], zero[N];
int prv[N], nxt[N];
int len, lenl, lenr;
int Z[2][2 * N];

void getZarr(int z[], string str)
{
    int n = str.length();
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
}

int main(){
    cin >> s >> sl >> sr;
    len = s.length(), lenl = sl.length(), lenr = sr.length();
    getZarr(Z[0], sl + "#" + s);
    getZarr(Z[1], sr + "#" + s);
    for(int cur = 0, i = 0; i < len; i++){
        if(s[i] != '0') cur = i;
        prv[i] = cur;
    }
    for(int cur = len, i = len-1; i >= 0; i--){
        if(s[i] != '0') cur = i;
        nxt[i] = cur;
    }
    int l, r;
    res[0][0] = res[1][0] = psum[0][0] = psum[1][0] = 1;
    for(int i = 0; i < len; i++){
        if(lenl <= i + 1){
            int st = lenl + 1 + i - lenl + 1;
            int len_match = Z[0][st];
            if(len_match == lenl || sl[len_match] < s[i - lenl + 1 + len_match]) r = i - lenl + 1;
            else r = i - lenl;
        }
        else r = -1;

        if(lenr <= i + 1){
            int st = lenr + 1 + i - lenr + 1;
            int len_match = Z[1][st];
            if(len_match == lenr || sr[len_match] > s[i - lenr + 1 + len_match]) l = i - lenr + 1;
            else l = i - lenr + 2;
        }
        else l = 0;

        ll cursum;
        if(!(0 <= l && l <= r && r <= i)) res[0][i+1] = res[1][i+1] = 0;
        else{
            cursum = psum[0][r] - (l == 0 ? 0 : psum[0][l-1]) + (s[i] == '0' && sl[0] == '0' ? res[1][i] : 0);
            if((i + 1 != len && s[i+1] == '0')) res[0][i+1] = 0;
            else res[0][i+1] = cursum;

            res[1][i+1] = cursum;
        }

        psum[0][i+1] = (psum[0][i] + res[0][i+1]) % mod;
    }

    cout << ((res[0][len] % mod) + mod) % mod << endl;


}