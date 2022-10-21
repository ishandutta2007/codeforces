#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e6 + 500;

int Z[MAXN],cnt[MAXN];


//str = "aabaacd"
//Z[] = {x, 1, 0, 2, 1, 0, 0}

//str = "abababab"
//Z[] = {x, 0, 6, 0, 4, 0, 2, 0}

void getZarr(string str)
{
    int n = str.length();
    int L, R, k;

    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;

            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;

            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                Z[i] = Z[k];

                // For example str = "aaaaaa" and i = 2, R is 5,
                // L is 0
            else
            {
                //  else start from R  and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

// Driver program
int main()
{
    string str;
    getline(cin, str);

    getZarr(str);
    fill(cnt, cnt + MAXN, 0);

    for(int i = 0; i < str.length(); i++){
        cnt[Z[i]]++;
    }
    for(int i = str.length()-1; i >= 0; i--){
        cnt[i] += cnt[i+1];
    }
    int res = 0;
    for(int i = str.length()-1; i > 0; i--){
        if(Z[i] + i == str.length() && cnt[Z[i]] > 1) res = max(res, Z[i]);
    }

    if(res == 0 ) cout << "Just a legend";
    else cout << str.substr(0,res);

    return 0;
}