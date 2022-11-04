#include <cassert>
#include <iostream>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

string randoms[52];

char c(int n) {
    return ('a' + (char)(n % 26));
}

void gen_randoms() {
    for (int i = 0; i < 52; i++)
        randoms[i] = (string() + (char)('A' + (char)(i / 26)) + c(i % 26));
}

signed main()
{
    
    gen_randoms();
    
    int n, k;
    cin >> n >> k;
    
    vector<bool> mas(n);
    for (int i = 0; i < n - k + 1; i++) {
        string s;
        cin >> s;
        mas[i] = (s == "NO");
    }
    
    int curs = 0;
    int cur = 0;
    vector<string> ans(n);
    int i = 0;
    for (i = 0; i < n - k + 1; i++) {
        if (mas[i]) {
            if (ans[i].size())
                ans[i + k - 1] = ans[i];
            else {
                ans[i] = randoms[curs++];
                ans[i + k - 1] = ans[i];
            }
        }
        else if (!ans[i].size())
            ans[i] = randoms[curs++];
    }
    
    for (; i < n; i++)
        if (!ans[i].size())
            ans[i] = randoms[curs++];
    
    for (auto it : ans)
        cout << it << ' ';
    
    return 0;
}