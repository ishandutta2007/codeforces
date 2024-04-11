#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

#define fr(i, n) for(int i = 0; i < n; i++)
#define fab(i, a, b) for(int i = a; i <= b; i++)

typedef long long ll;
typedef long double ld;

using namespace std;

string cut(string s, int l, int r){
    string k = "";
    fab(i, l, r - 1)
        k += s[i];
    return k;
}

void delet(string &s, int pos){
    string k = "";
    fr(i, pos) k += s[i];
    fab(i, pos + 1, s.length() - 1) k += s[i];
    s = k;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q, p, np, pr, len;
    string s, k;
    int l, r, ans[12];
    cin >> n >> q;
    cin >> s;
    fr(i, q){
        cin >> l >> r;
        fr(j, 10)
            ans[j] = 0;
        k = cut(s, l - 1, r);
        p = 0;
        np = 1;
        pr = 0;
        len = k.length();
        while(p >= 0 && p < len){
            //cerr << p << " " << len << "\n";
            if ((k[p] == '<' || k[p] == '>') && (pr != 0))
            {
                delet(k, p - np);
                if (np == 1)
                    p--;
                len--;
            }
            if (k[p] >= '0' && k[p] <= '9'){
                ans[k[p] - '0']++;
                if (k[p] == '0'){
                    delet(k, p);
                    len--;
                    pr = 0;
                    if (np == -1)
                      p--;
                    continue;
                }
                k[p]--;
            }
            if (k[p] == '>') pr = 1; else
            if (k[p] == '<') pr = -1; else
            pr = 0;
            if (k[p] == '<') np = -1;
            if (k[p] == '>') np = 1;

            p = p + np;
        }

        fr(j, 10) cout << ans[j] << " " ;
        cout << "\n";
    }
    return 0;
}