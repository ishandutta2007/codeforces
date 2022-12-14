#include <iostream>
using namespace std;
int t, cnt[1005];
string s;
int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        for(char c : s) ++cnt[c];
        for(int i=0; i<256; ++i) while (cnt[i] > 0) --cnt[i], cout << (char)i;
        cout << '\n';
    }
}