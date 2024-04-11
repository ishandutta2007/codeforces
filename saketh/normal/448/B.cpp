#include <iostream>
using namespace std;

string s, t;
int c1[26], c2[26];

int main(){
    cin >> s >> t;

    for(int i=0; i<s.length(); i++)
        c1[s[i]-'a']++;

    for(int i=0; i<t.length(); i++)
        c2[t[i]-'a']++;

    bool have_all = true;
    for(int i=0; i<26; i++)
        have_all &= c1[i] >= c2[i];

    if(!have_all){
        cout << "need tree" << endl;
        return 0;
    }

    if(s.length() == t.length()){
        cout << "array" << endl;
        return 0;
    }

    int i = 0, j = 0;
    for(; i < s.length(); i++){
        if(s[i] == t[j]){
            j++;
            if(j == t.length()) break;
        }
    }

    if(j == t.length())
        cout << "automaton" << endl;
    else
        cout << "both" << endl;

    return 0;
}