#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

string s,t,str;
int tlen;
int Z[200050];
int dp[100050], psum[100050], sum[100050];

void getZarr(string str)
{
    int n = str.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int main()
{
    getline(cin, s);
    getline(cin, t);
    tlen = t.length();
    str = t + "$" + s;
    getZarr(str);
    for(int i = 1; i <= s.length(); i++){
        if(i < t.length()) Z[i] = 0;
        else Z[i] = Z[i+1];
    }
    psum[0] = sum[0] = 0;
    //for(int i = 0; i <= s.length(); i++) cout << Z[i] << " ";
    //cout << endl;
    for(int i = 1; i <= s.length(); i++){
        if(Z[i] == tlen){
            dp[i] = psum[i-tlen] + 1;
        }else{
            dp[i] = dp[i-1];
        }
        sum[i] = (sum[i-1] + dp[i]) % mod;
        psum[i] = (psum[i-1] + sum[i] + 1) % mod;
    }
    int res = 0;
    for(int i = 1; i <= s.length(); i++){
        res = (res + dp[i]) % mod;
    }
    cout << res;


    return 0;
}