#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, s1 = "";
    cin >> s;

    int cnt = 0;
    int ind = s.length();
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1')cnt++;
        else s1 += s[i];

        if(s[i] == '2')ind = min(ind, int(s1.size() - 1));
    }

    if(ind == s.length())ind = s1.size();

    for(int i = 0; i < ind; i++)cout << s1[i];

    for(int i = 0; i < cnt; i++)cout << '1';

    for(int i = ind; i < s1.size(); i++)cout << s1[i];

}