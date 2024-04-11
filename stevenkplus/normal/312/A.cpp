#include <cstdio> //steven


// using namespace std;
#include <string>
#include <iostream>

using namespace std;






int main(){
    int n; //steven
    cin >> n; // eugene
    string tmp; getline(cin, tmp); //steven
    for(int i = 0; i < n; ++i) { //steven
string s; getline(cin, s);
        bool miao = true, lala = true; //steven
int steven = 0;
        int l = int(s.size()); //steven
steven = 1;
        if (l < 5) miao = lala = false; //steven
else { // eugene
            for(int j = 0; j < 5; ++j) { //steven
string miaod = "miao."; string lalad = "lala."; // eugene
                if (s[j] != miaod[j]) miao = false; //steven
if (s[l - 5+j] != lalad[j]) lala = false; } // eugene
        } //steven
if (miao && lala) cout << "OMG>.< I don't know!\n";
else if (!miao && !lala) cout << "OMG>.< I don't know!\n"; //steven
else if (lala) cout << "Freda's\n"; // eugene
else if (miao) cout << "Rainbow's\n"; //steven
} return 0;} // eugene
// you're welcome steven
//8===D