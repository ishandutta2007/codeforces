#include <bits/stdc++.h>
using namespace std;
 
int n, q;
vector<string> a, b, c, d, e, f;
set<string> solutions;
 
void process(string s) {
    if (s.length() == n)
        solutions.insert(s);
    else if (s.length() == 1)
        for (string op : a)
            process(op);
    else if (s[0] == 'a')
        for (string op : a)
            process(op + s.substr(1));
    else if (s[0] == 'b')
        for (string op : b)
            process(op + s.substr(1));
    else if (s[0] == 'c')
        for (string op : c)
            process(op + s.substr(1));
    else if (s[0] == 'd')
        for (string op : d)
            process(op + s.substr(1));
    else if (s[0] == 'e')
        for (string op : e)
            process(op + s.substr(1));
    else
        for (string op : f)
            process(op + s.substr(1));
}

int main() {
    cin >> n >> q;
    for (int i=0; i<q; i++) {
        string s;
        char ch;
        cin >> s >> ch;
        if (ch == 'a')
            a.push_back(s);
        else if (ch == 'b')
            b.push_back(s);
        else if (ch == 'c')
            c.push_back(s);
        else if (ch == 'd')
            d.push_back(s);
        else if (ch == 'e')
            e.push_back(s);
        else
            f.push_back(s);
    }
    
    process("a");
    
    cout << solutions.size() << endl;
    
    return 0;
}