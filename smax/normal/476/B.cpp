#include <bits/stdc++.h>
using namespace std;
 
int correctPos = 0;
double total = 0, correct = 0;
 
int recur(string s) {
    int pos = 0;
    for (int i=0; i<s.length()-1; i++) {
        if (s[i] == '?')
            return recur(s.substr(0, i) + '+' + s.substr(i+1)) + recur(s.substr(0, i) + '-' + s.substr(i+1));
        pos += s[i] == '+' ? 1 : -1;
    }
    if (s[s.length()-1] == '?')
        return recur(s.substr(0, s.length()-1) + '+') + recur(s.substr(0, s.length()-1) + '-');
    pos += s[s.length()-1] == '+' ? 1 : -1;
    total++;
    if (pos == correctPos)
        correct++;
    return 0;
}
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (char c : s1)
        correctPos += c == '+' ? 1 : -1;
    
    recur(s2);
    cout << setprecision(9) << correct / total << endl;
    
    return 0;
}