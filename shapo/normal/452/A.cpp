#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const vector< string > poks =
{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool
ok(const string &from, const string &to)
{
    if (from.size() != to.size()) {
        return false;
    }
    for (int i = 0; i < int(from.size()); ++i) {
        if (to[i] != '.' && to[i] != from[i]) {
            return false;
        }
    }
    return true;
}

int
main()
{
    int len;
    string s;
    cin >> len >> ws >> s;
    for (auto poke : poks) {
        if (ok(poke, s)) {
            cout << poke;
            break;
        }
    }
    return 0;
}