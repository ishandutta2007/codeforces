#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
string str;
int s[MAXN];

ll res[MAXN];
int last[26];

vector <int> t;

int main()
{
    cin >> str;
    N = str.length();
    for (int i = 0; i < N; i++)
        s[i] = str[i] - 'a';
    
    for (int i = 0; i < N; i++)
        res[i] = 0;
    for (int i = 0; i < 26; i++)
        last[i] = 1e9;
    
    for (int i = N - 1; i >= 0; i--)
    {
        last[s[i]] = i;
        
        t.clear();
        for (int j = 0; j < 26; j++)
            if (last[j] < N)
                t.push_back (last[j]);
        sort (t.begin(), t.end());
        
        t.push_back (N);
        for (int j = 1; j < t.size(); j++)
            res[j] += (t[j] - t[j-1]);
    }
    
    int ans = 1;
    while (res[ans])
        ans++;
    
    cout << ans - 1 << "\n";
    for (int i = 1; i < ans; i++)
        cout << res[i] << "\n";
    return 0;
}