#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
string s;
int arr[210];
vector <int> res;

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B') arr[i] = 1;
        else arr[i] = 0;
    }

    for (int i = 1; i + 1 < s.length(); i++)
    {
        if (arr[i] != arr[i-1])
        {
            res.push_back(i);
            arr[i] = 1 - arr[i];
            arr[i+1] = 1 - arr[i+1];
        }
    }

    if (arr[N-2] != arr[N-1])
    {
        if (N % 2 == 0)
        {
            cout << "-1\n";
            return 0;
        }
        for (int i = 0; i + 1 < N; i += 2)
            res.push_back (i);
    }
    cout << res.size() << "\n";
    for (int x : res) cout << x + 1 << " ";
        cout << "\n";
}