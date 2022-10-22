#include <algorithm>
#include <iostream>
using namespace std;

int d[600000];

int main()
{
    int k;
    string s;
    cin >> k >> s;
    s += '!';
    reverse(s.begin(), s.end());
    for(int i = (1 << k); i < (1 << (k + 1)); i++) d[i] = 1;
    for(int i = (1 << k) - 1; i > 0; i--){
        if(s[i] != '1') d[i] += d[i * 2 + 1];
        if(s[i] != '0') d[i] += d[i * 2];
    }
    int q;
    cin >> q;
    while(q--){
        int p;
        char c;
        cin >> p >> c;
        p = (1 << k) - p;
        int t = 0;
        if(s[p] != '1') t -= d[p * 2 + 1];
        if(s[p] != '0') t -= d[p * 2];
        s[p] = c;
        if(s[p] != '1') t += d[p * 2 + 1];
        if(s[p] != '0') t += d[p * 2];
        while(p){
            d[p] += t;
            if(s[p / 2] - '0' == p % 2) break;
            p /= 2;
        }
        cout << d[1] << endl;
    }
}