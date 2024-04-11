#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int MD = 51123987;

int n;
char c[200];
int a[200];
//int d[22804][52][52];

int d[152][52][52];
int d1[152][52][52];
int d2[152][52][52];
int d3[152][52][52];

int fs(int x, int n)
{
    for (int i = n; i >= 1; i --)
        if (a[i] == x) return i;
    return -1;
}

int code[200][200];
bool have[5];

set < string > S;

void rec(string s)
{
    if (S.count(s) != 0) return;
    S.insert(s);

    for (int i = 0; i < (int)(s.size()) - 1; i ++)
    {
        char s1 = s[i], s2 = s[i + 1];
        s[i + 1] = s1;
        rec(s);
        s[i] = s2, s[i + 1] = s2;
        rec(s);
        s[i] = s1; s[i + 1] = s2;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d\n", &n);
    gets(c);
    for (int i = 0; i < n; i ++)
        a[i + 1] = c[i] - 'a' + 1;

    int cd = 0;
    for (int i = 0; i <= 150; i ++)
        for (int j = 0; j <= 150; j ++)
            cd ++, code[i][j] = cd;

    //d[code[0][0]][0][0] = 1;

    //for (int i = 0; i <= 150; i ++)
    //    d[i][0][0] = d1[i][0][0] = d2[i][0][0] = d3[i][0][0] = 1;

    for (int i = 1; i <= n; i ++)
    {
        for (int k = 0; k <= n; k ++)
            for (int l = 0; l < 52; l ++)
                for (int r = 0; r < 52; r ++)
                    d[k][l][r] = 0;

        d[0][0][0] = 1;
        for (int j = 1; j <= n; j ++)
            for (int k = 0; k <= j; k ++)
                for (int l = 0; l + k <= j; l ++)
                    for (int r = 1; r <= 3; r ++)
                    {
                        if (k >= 52 || l >= 52 || j - k - l >= 52) continue;
                        if (r == 1 && k == 0) continue;
                        if (r == 2 && l == 0) continue;
                        if (r == 3 && k + l == j) continue;
                        //int p = fs(r, i);
                        //if (p == -1) continue;
                        
                        if (!have[r] && a[i] != r) continue;

                        //d[code[i][j]][k][l] += d[code[p][j - 1]][x][y];
                        //d[code[i][j]][k][l] %= MD;
                        //d[j][k][l] += d[
                        int x = k, y = l;
                        if (r == 1) x --;
                        if (r == 2) y --;

                        if (a[i] == r)
                        {
                            d[j][k][l] += d[j - 1][x][y];
                            d[j][k][l] %= MD;
                        } else
                        {
                            if (r == 1)
                            {
                                d[j][k][l] += d1[j - 1][x][y];
                                d[j][k][l] %= MD;
                            } else
                            if (r == 2)
                            {
                                d[j][k][l] += d2[j - 1][x][y];
                                d[j][k][l] %= MD;
                            } else
                            {
                                d[j][k][l] += d3[j - 1][x][y];
                                d[j][k][l] %= MD;
                            }
                        }
                    }
        if (a[i] == 1)
        {
            for (int k = 0; k <= 150; k ++)
                for (int l = 0; l < 52; l ++)
                    for (int r = 0; r < 52; r ++)
                        d1[k][l][r] = d[k][l][r];

            have[1] = true;
        }
        if (a[i] == 2)
        {
            for (int k = 0; k <= 150; k ++)
                for (int l = 0; l < 52; l ++)
                    for (int r = 0; r < 52; r ++)
                        d2[k][l][r] = d[k][l][r];

            have[2] = true;
        }
        if (a[i] == 3)
        {
            for (int k = 0; k <= 150; k ++)
                for (int l = 0; l < 52; l ++)
                    for (int r = 0; r < 52; r ++)
                        d3[k][l][r] = d[k][l][r];

            have[3] = true;
        }
    }

    int res = 0;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j + i <= n; j ++)
        {
            int k = n - i - j;
            if (-1 <= i - j && i - j <= 1 && -1 <= i - k && i - k <= 1 && -1 <= j - k && j - k <= 1)
                res += d[n][i][j], res %= MD;
        }

    printf("%d\n", res);

    /*string s = "";
    for (int i = 0; i < n; i ++)
        s += c[i];

    rec(s);
    int ans = 0;
    for (set < string > ::iterator it = S.begin(); it != S.end(); it ++)
    {
        int i = 0, j = 0, k = 0;
        string cur = *it;
        for (int t = 0; t < cur.size(); t ++)
            if (cur[t] == 'a') i ++; else
                if (cur[t] == 'b') j ++; else 
                    k ++;
        if (-1 <= i - j && i - j <= 1 && -1 <= i - k && i - k <= 1 && -1 <= j - k && j - k <= 1)
                ans ++, cout << cur << endl;
    }
    cout << ans << endl;*/
    return 0;
}