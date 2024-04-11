#include <bits/stdc++.h>
using namespace std;

const int N = 5050;

int n;
string ini[N], rev[N];
char c[N];

//#define DEBUG

string s, t;

int f[N];
int l[N], r[N];
bool same[N];

void store(string &s){
    int len = strlen(c);
    for(int i = 0; i < len; i++) s.push_back(c[i]);
}

void getnext(){
    int m = t.length();
    f[0] = 0; f[1] = 0;
    for(int i = 1; i < m; i++){
        int j = f[i];
        while(j && t[i] != t[j]) j = f[j];
        f[i+1] = t[i] == t[j] ? j + 1 : 0;
    }
}

int find(){
    int n = s.length(), m = t.length();
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j && t[j] != s[i]) j = f[j];
        if(t[j] == s[i]) j++;
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}

bool check(int j){
    char ci = '0', ce = '0';
    for(int i = 0; i < n; i++){
        int nj = l[i] + j;
        if(!same[i]){
            if(!(nj >= 0 && nj < ini[i].length())) return false;
            if(ci == '0') ci = ini[i][nj];
            else if(ci != ini[i][nj]) return false;
            if(ce == '0') ce = rev[i][nj];
            else if(ce != rev[i][nj]) return false;
        }
    }
    return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);


//    scanf("%d", &n);
//
//    getchar();
    cin >> n;
    getline(cin, ini[0]);
    for(int i = 0; i < n; i++){
//        gets(c);
//        store(ini[i]);
//        cin >> ini[i];
        getline(cin, ini[i]);
    }
    for(int i = 0; i < n; i++){
//        gets(c);
//        store(rev[i]);
        getline(cin, rev[i]);
    }

    int fir = N;
    for(int i = 0; i < n; i++){
        l[i] = N, r[i] = -1, same[i] = true;
        for(int j = 0; j < ini[i].length(); j++){
            if(ini[i][j] != rev[i][j]){
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
                same[i] = false;
                fir = min(fir, i);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!same[i] && r[i] - l[i] != r[fir] - l[fir]) return cout << "NO", 0;
    }
    string st = ini[fir].substr(l[fir], r[fir] - l[fir] + 1);
    string ed = rev[fir].substr(l[fir], r[fir] - l[fir] + 1);
    for(int i = 0; i < n; i++){
        if(!same[i]){
            if(ini[i].substr(l[i], r[i] - l[i] + 1) != st) return cout << "NO", 0;
            if(rev[i].substr(l[i], r[i] - l[i] + 1) != ed) return cout << "NO", 0;
        }
    }

    int lex = 0, rex = r[fir] - l[fir];
    while(check(lex-1)) lex--;
    while(check(rex + 1)) rex++;

    st = ini[fir].substr(l[fir] + lex, rex - lex + 1);
    ed = rev[fir].substr(l[fir] + lex, rex - lex + 1);

    t = st;
    getnext();

    for(int i = 0; i < n; i++){
        if(same[i]){
            s = ini[i];
            if(find() != -1) return cout << "NO", 0;
        }
        else{
            s = ini[i];
            if(find() != l[i] + lex) return cout << "NO", 0;
        }
    }

    cout << "YES" << endl;
    cout << st << endl;
    cout << ed << endl;

}