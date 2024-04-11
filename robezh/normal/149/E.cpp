#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, M = (int)1e4 + 500;

string s, t;
int f[M], p[2][N];
bool rev = false;


void getnext(){
    int m = t.length();
    f[0] = 0; f[1] = 0;
    for(int i = 1; i < m; i++){
        int j = f[i];
        while(j && t[i] != t[j]) j = f[j];
        f[i+1] = t[i] == t[j] ? j + 1 : 0;
    }
}


void kmp(){
    int n = s.length(), m = t.length();
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j && t[j] != s[i]) j = f[j];
        if(t[j] == s[i]) j++;
        if(!rev) p[rev][i] = j;
        else p[rev][n-1-i] = j;
        if(j == m) j = f[j];
    }
}

bool check(){
    getnext();
    kmp();

    rev = true;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    getnext();
    kmp();

    rev = false;
    reverse(s.begin(), s.end());

    int n = s.length();

    for(int i = 1; i < n; i++) p[0][i] = max(p[0][i-1], p[0][i]);
    for(int i = n-2; i >= 0; i--) p[1][i] = max(p[1][i+1], p[1][i]);
    for(int i = 0; i < n-1; i++){
        if(p[0][i] + p[1][i+1] >= t.length()) return true;
    }
    return false;


}


int main(){
    getline(cin, s);
    int n, ans = 0;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, t);
        if(t.length() == 1) continue;
        ans += check();
    }
    cout << ans << endl;
}