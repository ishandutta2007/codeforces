#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool use[201000];
    int prev[201000];
    int next[201000];
    for (int a = 0; a < 201000; a++)
    {
        use[a] = true;
        prev[a] = a - 1;
        next[a] = a + 1;
    }
    next[s.length()-1] = -1;
    for (int a = 0; a != -1; a = next[a])
    {
        if (next[a] == -1)
                continue;
        if (use[a] && use[next[a]] && (s[a] == s[next[a]]))
        {
            use[a] = false;
            use[next[a]] = false;
            next[prev[a]] = next[next[a]];
            prev[next[next[a]]] = prev[a];
            int cur = prev[a];
            while (cur != -1 && next[cur] != -1)
            {
                if (s[cur] != s[next[cur]])
                   break;
                use[cur] = false;
                use[next[cur]] = false;
                if (prev[cur] != -1)
                                next[prev[cur]] = next[next[cur]];
                if (next[next[cur]] != -1)
                                prev[next[next[cur]]] = prev[cur];
                if (prev[cur] != -1)
                cur = prev[cur];
                else
                                break;
            }    
            a = cur;
        }
    }
    for (int a = 0; a < s.length(); a++)
    {
        if (use[a])
                cout << s[a];
    }
    cout << "\n";
    //system ("Pause");
    return 0;
}