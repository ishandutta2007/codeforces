#include <iostream>
#include <string>

using namespace std;
const int MAXN = 51;

string s;

int main()
{
    int N; cin >> N;
    cin >> s;
    int ans = 0;
    for (int i = 2; i < N; i++)
        if (s[i] == 'x' && s[i-1] == 'x' && s[i-2] == 'x')
            ans++;
    cout << ans << "\n";
}