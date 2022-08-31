#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

char c[3] = {'0', 'a', 'A'};

void run()
{
    string s; cin >> s;
    int b[3];
    b[0] = b[1] = b[2] = 0;
    int M = s.length();
    int ns = 0;
    for (int i = 0; i < M; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (b[0]) ns = i;
            b[0] = 1;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (b[1]) ns = i;
            b[1] = 1;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (b[2]) ns = i;
            b[2] = 1;
        }
    }

    if (b[0] + b[1] + b[2] == 3)
        cout << s << "\n";
    else if (b[0] + b[1] + b[2] == 2)
    {
        int bloc = -1;
        for (int i = 0; i < 3; i++) if (!b[i]) bloc = i;
        s[ns] = c[bloc];
        cout << s << "\n";
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (!b[i]) cout << c[i];
        }
        for (int i = 2; i < M; i++) cout << s[i];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        run();
}