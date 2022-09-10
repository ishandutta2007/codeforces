#include <bits/stdc++.h>

using namespace std;

int n;
string S[407];

deque<char> s;

inline char pback() {
    char c = s.back();
    s.pop_back();
    char c2 = s.back();
    s.push_back(c);
    return c2;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> S[i];

    for(int i = 0 ; i < n ; i++) {
        for(char c : S[i]) {
            s.push_back(c);
            while(s.size() >0 && s.back() == 'u') {
                s.pop_back();
                s.push_back('o');
                s.push_back('o');
            }
        }

        S[i] = "";
        while(!s.empty())
            S[i] += s.front(), s.pop_front();

        for(char c : S[i]) {
            s.push_back(c);
            while(s.size() >1 && pback() == 'k' && s.back() == 'h') {
                s.pop_back();
                s.pop_back();
                s.push_back('h');
            }
        }

        S[i] = "";
        while(!s.empty())
            S[i] += s.front(), s.pop_front();

       // cout << S[i] << endl;
    }

    sort(S, S + n);

    int groups = 1;
    for(int i = 0 ; i < n - 1 ; i++)
        if(S[i + 1] != S[i])
            groups++;

    cout << groups << endl;

    return 0;
}