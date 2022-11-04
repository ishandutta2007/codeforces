#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    char color[4];
    int cnt[4] = {0};
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != '!')
            color[i & 3] = s[i];
        else
            cnt[i & 3]++;
    }
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j)
            if (color[j] > color[j + 1])
            {
                swap(color[j], color[j + 1]);
                swap(cnt[j], cnt[j + 1]);
            }
    cout << cnt[2] << " " << cnt[0] << " " << cnt[3] << " " << cnt[1] << endl;
}