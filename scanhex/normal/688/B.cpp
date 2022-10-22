#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
//    cout << "Hello, World!" << endl;
    string s; cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    cout << s << s1 << endl;
    return 0;
}