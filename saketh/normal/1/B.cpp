#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
string s;

bool alph(int i){ return 'A' <= s[i] && s[i] <= 'Z'; }
bool num(int i){ return !alph(i); }

int l2n(string col){
    int res = 0;
    for(char c : col) res = 26 * res + (c-'A'+1);
    return res;
}

string n2l(int val){
    string res = "";
    while(val > 0){
        int ld = val % 26;
        if(ld == 0) ld = 26;
        res = res + (char)('A'+ld-1);
        val -= ld;
        val /= 26;
    }    
    reverse(res.begin(), res.end());
    return res;
}

void conv(){
    int i = 0;
    while(i<s.length() && alph(i)) i++;
    int j = i;
    while(j<s.length() && num(j)) j++;

    if(j == s.length()){
        string col = s.substr(0, i);
        string row = s.substr(i);
        cout << "R" << row << "C" << l2n(col) << "\n";
    }
    else{
        string col = s.substr(j+1);
        string row = s.substr(1, j-1);
        cout << n2l(atoi(col.c_str())) << row << "\n";
    }
}

int main(){
    for(cin >> N; N; N--){
        cin >> s;
        conv();
    }
    cout.flush();
    return 0;
}