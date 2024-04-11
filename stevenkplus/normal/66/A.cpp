/* hi travis
* hi steven
* turn order: travis, steven
*/
//http://codeforces.com/problemset/problem/66/A
#include <cstdio> //travis
#include <algorithm> //steven, reading problem. i can solve it now. we need <iostream>

#include <iostream>

using namespace std; //steven

int main() { // travis
    string ar[5] = {"byte", "short", "int", "long", "BigInteger"}; //steven what are you doing ok nvm btw it's positive
    string strs[4][2] = {{"128","127"},{"32768","32767"},{"2147483648","2147483647"},{"9223372036854775808","9223372036854775807"}};
    string input; cin >> input; //steven
    for (int i = 0; i < 4; i++) { // oops didn't notice positivity, lol
        int strlen = input.length(); //steven also 
        if (strlen < strs[i][1].size() || (strlen == strs[i][1].size() && input <= strs[i][1])) { // travis
            cout << ar[i] << endl; //steven
            return 0; //travis
        } //steven
    } // travis
    cout << ar[4] << endl; //steven
} //t ravis



//steven submitted
//wrong answer oops
// fuck i screwed up 127 vs 128

//fixed it's k still wa on test 11 now
//try again
//you changed something?