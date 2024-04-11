#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;
const int mod = (int)1e9 + 7;

int n,m,a,b,len;
string str;

ll val[N][30];
ll p = 137, pw[N];

int get(int i, int l, int r){
    ll res = (val[r][i] - val[l-1][i] + mod) * (pw[n-l]) % mod;
    return (int)res;
}


int main(){
    scanf("%d%d", &n, &m);
    getchar();
    getline(cin, str);

    pw[0] = 1;
    for(int i = 1; i <= n+5; i++) pw[i] = pw[i-1]*p%mod;

    str = " " + str;
    val[1][str[1]-'a'] = pw[1];
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 26; j++){
            if(str[i] == ('a'+j)) val[i][j] = (val[i-1][j] + pw[i]) % mod;
            else val[i][j] = val[i-1][j];
        }
    }
    for(int i = 0; i < m; i++){
        vector<int> A,B;
        scanf("%d%d%d", &a, &b, &len);
        for(int j = 0; j < 26; j++){
            A.push_back(get(j, a, a+len-1));
            B.push_back(get(j, b, b+len-1));
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if(A == B) printf("YES\n");
        else printf("NO\n");
    }
}