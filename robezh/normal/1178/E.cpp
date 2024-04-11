#include <bits/stdc++.h>
using namespace std;

int n ;
string str;
string res;
int odd = 0;

void choose(int l, int r) {
    if(str[l] == str[r]) res.push_back(str[r]);
    else if(str[l-1] == str[r]) res.push_back(str[r]);
    else if(str[l] == str[r+1]) res.push_back(str[l]);
    else if(str[l-1] == str[r+1]) res.push_back(str[l-1]);
    else assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    n = str.length();
    int l, r, mid;
    if(n % 4 != 0) {
        odd = 1;
        res.push_back(str[n / 2]);
        l = n / 2 - 1;
        r = n / 2 + 1;
    }
    else {
        l = n / 2 - 1;
        r = n / 2;
    }
    while(l >= 1 && r <= n - 2) {
        choose(l, r);
        l -= 2, r += 2;
    }
    string rres = res;
    reverse(rres.begin(), rres.end());
    if(odd) rres.pop_back();
    cout << rres + res << endl;



}