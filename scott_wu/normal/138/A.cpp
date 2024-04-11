#include <iostream>
#include <string>

using namespace std;

int n, k;
string a, b, c, d;
char vow[5] = {'a', 'e', 'i', 'o', 'u'};

bool rhyme (string left, string right)
{
    int sl, sr;
    int lc = 0, rc = 0;
    for (int i = left.length() - 1; i >= 0; i--)
    {
        bool check = true;
        for (int j = 0; j < 5; j++)
            if (left[i] == vow[j])
                check = false;
        if (!check)
        {
            lc++;
            if (lc == k)
                sl = i;
        }
    }
    for (int i = right.length() - 1; i >= 0; i--)
    {
        bool check = true;
        for (int j = 0; j < 5; j++)
            if (right[i] == vow[j])
                check = false;
        if (!check)
        {
            rc++;
            if (rc == k)
                sr = i;
        }
    }
    if (lc < k || rc < k)
        return false;
    if (left.length() - sl != right.length() - sr)
        return false;
    for (int i = 0; i < left.length() - sl; i++)
        if (left[i + sl] != right[i + sr])
            return false;
    return true;
}

int scheme ()
{
    if (rhyme (a, b) && rhyme (b, c) && rhyme (c, d))
        return 7;
    if (rhyme (a, b) && rhyme (c, d))
        return 1;
    if (rhyme (a, c) && rhyme (b, d))
        return 2;
    if (rhyme (a, d) && rhyme (b, c))
        return 4;
    return 0;
}

int main()
{
    int ans = 7;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        ans &= scheme();
    }
    string res;
    if (ans == 0) res = "NO";
    if (ans == 1) res = "aabb";
    if (ans == 2) res = "abab";
    if (ans == 4) res = "abba";
    if (ans == 7) res = "aaaa";
    cout << res << "\n";
    //system ("Pause");
    return 0;
}