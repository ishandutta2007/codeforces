#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int coul=0, cour=0;
    for (int i = 0; i < n; i++)
        if (s[i] == '(')
            coul++;
        else if (s[i] == ')')
            cour++;
    if (s[n-1] == '?') {
        s[n-1] = ')';
        cour++;
    }

    if (coul > n/2 || cour > n/2 || s[n-1] == '(') {
            cout << ":(";
            return 0;
        }

    int curl=0, curr=0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            curl++;
        }
        if (s[i] == ')') {
            curr++;
        }
        if (s[i] == '?') {
            if (coul < n/2) {
                s[i] = '(';
                curl++;
                coul++;
            }
            else {
                s[i] = ')';
                curr++;
            }
        }
        if (curr == curl && i < n-1) {
            cout << ":(";
            return 0;
        }

    }

    cout << s << endl;
    return 0;
}