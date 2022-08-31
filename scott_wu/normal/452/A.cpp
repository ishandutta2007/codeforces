#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

string str[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", 
    "leafeon", "glaceon", "sylveon"};

int N;
string s;

bool match (string left, string right)
{
    if (left.length() != right.length()) return false;
    for (int i = 0; i < left.length(); i++)
        if (left[i] != right[i] && left[i] != '.')
            return false;
    return true;
}

int main()
{
    cin >> N >> s;
    for (int i = 0; i < 8; i++)
        if (match (s, str[i]))
        {
            cout << str[i] << "\n";
            break;
        }
    return 0;
}