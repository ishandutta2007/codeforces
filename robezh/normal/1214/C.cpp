#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string str;
stack<char> S;
int n;

int main() {
    cin >> n;
    cin >> str;
    int cnt = 0;
    for(char c : str) cnt += (c == '(');
    if(cnt * 2 != n) return cout << "No" << endl, 0;
    for(char c : str) {
        if(!S.empty() && c == ')' && S.top() == '(') S.pop();
        else S.push(c);
    }
//    cout << S.size() << endl;
    cout << (S.size() <= 2 ? "Yes" : "No") << endl;
}