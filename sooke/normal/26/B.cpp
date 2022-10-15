#include <iostream>
#define Maxn 1000001

using namespace std;

int len , ans , v;
string s;

int main(){
    cin >> s;
    len = s.size();
    s = " " + s;
    for(int i = 1 ; i <= len ; i++)
        if(s[i] == '(')
            v++;
        else{
            if(v != 0)
            	ans += 2 , v--;
        }
    cout << ans << endl;
    return 0;
}

// By Sooke.
// CF26B Regular Bracket Sequence.