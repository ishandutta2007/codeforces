#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char s[n];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int l, r;
    char c1, c2;
    for(int i = 0; i < m; i++)
    {
        cin >> l >> r >> c1 >> c2;
        for(int j = l - 1; j < r; j++)
        {
            if(s[j] == c1)
                s[j] = c2;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    return 0;
}