#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, s1 = "";
    int n, ncu=0, ncuva=0;
    cin >> s;
    n = s.length();
    string s2="",s3="";
    while (ncuva < n) {
        s1 += s[ncu];
        if (s[ncu] != 'a') {
            ncuva++;
            s2 += s[ncu];
        }
        ncu++;
        n--;
    }
    while (ncu < s.length()) {
        s3 += s[ncu];
        ncu++;
    }
    if (s2 != s3)
        cout << ":(" << endl;
    else
        cout << s1 << endl;
    return 0;
}