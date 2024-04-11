#include <bits/stdc++.h>

using namespace std;

int n;

bool palin(string s) {
    for(int i = 0; i < n; i++)
        if(s[i] != s[n - 1 - i])
            return false;
    return true;
}

int main() {
	string s;
	cin >> s;
	bool eq = true;
	for(int i = 1; i < s.length(); i++)
	    if(s[i] != s[i - 1])
	        eq = false;
	        
	if(eq) {
	    cout << "Impossible\n";
	    return 0;
	}
    n = s.length();
	for(int i = 1; i < n; i++) {
	    string t = "";
	    for(int j = 0; j < n; j++)
	        t += s[(i + j)%n];
	    if(t == s)
	        continue;
	    //cout << t << endl;
	    if(palin(t)) {
	        cout << 1 << endl;
	        return 0;
	    }
	}
	map<char, int> ct;
	for(auto c : s)
	    ct[c]++;
	for(auto p : ct) {
	    if(p.second == n - 1) {
	        cout << "Impossible\n";
	        return 0;
	    }
	}
	cout << 2 << endl;
}