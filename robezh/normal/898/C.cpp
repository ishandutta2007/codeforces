#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

bool is_suffix(string b, string a){
    for(int i = 0; i < a.length(); i++ ){
        if(a.substr(i, a.length()) == b) return true;
    }
    return false;
}

int main(){
    map<string, set<string>> M;
    int n,k;
    cin >> n;
    string name, phone;
    while(n-- > 0){
        cin >> name >> k;
        while(k--){
            cin >> phone;
            M[name].insert(phone);
        }
    }
    cout << M.size() << endl;
    for(auto m : M){
        set<string> s = m.second;
        for(auto str : m.second)
            for(int i = 1; i < str.length(); i++)
                if(s.count(str.substr(i, str.length())))
                    s.erase(str.substr(i, str.length()));
        cout << m.first << " " << s.size();
        for(auto str : s){cout << " " << str;}
        cout << endl;

    }

    return 0;
}