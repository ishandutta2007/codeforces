#include <bits/stdc++.h>
using namespace std;

int wval[105], val[105], suff[105], dpmx[105][55], dpmn[105][55];

int main() {
    string s;
    int n;
    cin >> s >> n;
    int cval = 1;
    for(int i = 1; i <= s.length(); i++) {
        wval[i] = cval;
        if(s[i - 1] == 'F')
            val[i] = cval;
        else
            cval *= -1;
    }
    for(int i = s.length(); i >= 1; i--)
        suff[i] = suff[i + 1] + val[i];
    //for(int i = 1; i <= s.length() + 1; i++)
    //    cout << suff[i] << " ";
    //cout << endl;
    dpmx[0][0] = dpmn[0][0] = suff[1];
    for(int pos = 1; pos <= s.length(); pos++) {
        dpmx[pos][0] = dpmn[pos][0] = suff[1];
        for(int c = 1; c <= min(pos, n); c++) {
            int sgn = (c % 2 ? 1 : -1);
            if(c < pos)
                dpmx[pos][c] = dpmx[pos - 1][c];
            else
                dpmx[pos][c] = -1000000;
            //cout << dpmx[pos - 1][c - 1] << " " << val[pos] << " " << suff[pos + 1] << "    " << -sgn*val[pos] << endl;
            if(s[pos - 1] == 'F')
                dpmx[pos][c] = max(dpmx[pos][c], dpmx[pos - 1][c - 1] - sgn*val[pos] - 2*sgn*suff[pos + 1]);
            else
                dpmx[pos][c] = max(dpmx[pos][c], dpmx[pos - 1][c - 1] + sgn*wval[pos] - 2*sgn*suff[pos + 1]);
            if(c < pos)
                dpmn[pos][c] = dpmn[pos - 1][c];
            else
                dpmn[pos][c] = 1000000;
            if(s[pos - 1] == 'F')
                dpmn[pos][c] = min(dpmn[pos][c], dpmn[pos - 1][c - 1] - sgn*val[pos] - 2*sgn*suff[pos + 1]);
            else
                dpmn[pos][c] = min(dpmn[pos][c], dpmn[pos - 1][c - 1] + sgn*wval[pos] - 2*sgn*suff[pos + 1]);
            //cout << pos << " " << c << " " << dpmx[pos][c] << " " << dpmn[pos][c] << endl;
        }
    }
    int ans = 0;
    for(int k = n; k >= 0; k -= 2)
        ans = max({ans, dpmx[s.length()][k], -dpmn[s.length()][k]});
    cout << ans << endl;
}