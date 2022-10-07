#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main() {
    string cur;
    string ss; 
    getline(cin, ss);
    ss = ss.substr(1, ss.size() - 2); 
    for(int i = 0; i <= ss.size(); ++i) {
        if (i == ss.size() || ss[i] == ',') {
            s.insert(cur);
            cur = ""; 
        } else if (ss[i] != ' ') {
            cur += ss[i];
        }   
    }   
   s.insert("");
    cout << s.size() - 1<< endl;
}