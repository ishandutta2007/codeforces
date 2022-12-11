#include <bits/stdc++.h>

using namespace std;

set <char> s;
char ch;
int n;

int main()	{

    cin >> n;
    while (n --> 0) {
        cin >> ch;
        s.insert(tolower(ch));
    }
    if (s.size() == 26)
        cout << "YES\n";
    else
        cout << "NO\n";
	return 0;

}