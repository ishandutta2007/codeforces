#include <iostream>
#include <vector>

using namespace std;

vector<int> stringCnv(string s) {
    vector<int> r;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+')
            r.push_back(s[i] - '0');
    }

    return r;
}

int main()
{
    string s;
    cin >> s;

    vector<int> v = stringCnv(s);

    int a[3] = {0};

    for (int i = 0; i < v.size(); i++) {
        a[v[i] - 1]++;
    }

    string result = "";
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < a[j]; i++) {
            result += char(j + 1 + '0');
            result += '+';
        }
    }

    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i];
    }
    return 0;
}