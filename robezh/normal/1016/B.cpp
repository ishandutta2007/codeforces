#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n,m,q,a,b;
string str, ttr;
int slen, tlen;
int psum[N];

int main() {
    cin >> n >> m >> q;
    cin >> str >> ttr;
    slen = str.length(), tlen = ttr.length();
    fill(psum, psum+N, 0);
    for(int i = 0; i <= slen - tlen; i++){
        if(str.substr(i, tlen) == ttr) psum[i]++;
    }
    for(int i = 1; i <= slen - tlen; i++) psum[i] += psum[i-1];
    while(q--){
        cin >> a >> b;
        a--, b--;
        b -= (tlen-1);
        if(b < 0 || b < a) cout << 0 << endl;
        else cout << psum[b] - (a == 0 ? 0 : psum[a-1]) << endl;
    }
}