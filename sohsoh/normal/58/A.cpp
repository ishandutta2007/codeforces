#include <iostream>

using namespace std;

int main()
{
    string s, hello = "hello;";
    cin >> s;

    int point = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == hello[point]) {
            point++;
        }
    }

    if (point >= 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}