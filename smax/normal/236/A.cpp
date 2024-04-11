#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> letters;
    string s;
    cin >> s;
    for (char c : s)
        letters.insert(c);
    if (letters.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    
    return 0;
}