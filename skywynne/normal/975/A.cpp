#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
string S[N];
set < string > st;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
        string tt = "";
        for (int j = 0; j < 26; j++)
        {
            int w = 0;
            for (int h = 0; h < S[i].size(); h ++)
                if (S[i][h] == j + 'a')
                    w = 1;
            if (w)
                tt += j + 'a';
        }
        sort(tt.begin(), tt.end());
        st.insert(tt);
    }
    cout << st.size();
    return (0);
}