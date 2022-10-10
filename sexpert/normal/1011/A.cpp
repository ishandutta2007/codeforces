
#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<char> st;
    int n, k, count = 0, sum = 0;
    string s;
    cin >> n >> k >> s;
    for(char c : s) st.insert(c);
    //for(auto c : st) cout << c << " ";
    char last = 'a' - 2;
    for(auto c : st)
    {
        if(c - last > 1)
        {
            sum += c - 'a' + 1;
            count++;
            last = c;
        }
        if(count == k) break;
    }
    if(count < k) cout << -1;
    else cout << sum;
}