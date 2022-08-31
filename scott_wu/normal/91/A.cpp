#include <iostream>
#include <string>

using namespace std;

const int MAXN = 10100;

string heading, goal;
int next[MAXN][26]; // next of this char from this pos

int main()
{
    cin >> heading >> goal;
    for (int a = 0; a < MAXN; a++)
        for (int b = 0; b < 26; b++)
            next[a][b] = -1;
    string hdouble = heading + heading;
    for (int a = 0; a < heading.length(); a++)
        for (int b = 1; b <= heading.length(); b++)
            if (next[a][hdouble[a+b] - 'a'] == -1)
                next[a][hdouble[a+b] - 'a'] = b;
    long long total = 0;
    int start;
    for (int a = heading.length() - 1; a >= 0; a--)
        if (heading[a] == goal[0])
            start = a;
    total = start;
    for (int a = 1; a < goal.length(); a++)
    {
        long long temp = total % heading.length();
        if (next[temp][goal[a] - 'a'] == -1)
        {
            cout << "-1\n";
            return 0;
        }
        total += next[temp][goal[a] - 'a'];
    }
    cout << total / heading.length() + 1 << "\n";
    return 0;
}