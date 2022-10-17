#include <iostream>
using namespace std;

string a, b, c;
char ct[26];

void upd(string s, int m){
    for(char l : s)
        ct[l-'A'] += m;
}   

int main(){
    cin >> a >> b >> c;
    upd(a, 1);
    upd(b, 1);
    upd(c, -1);

    bool good = true;
    for(int c : ct)
        good &= !c;
    cout << (good ? "YES" : "NO") << endl;
}