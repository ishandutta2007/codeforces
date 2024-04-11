#include <cstdio>
#include <iostream>

using namespace std;

bool luck(string s) {
    int z = int(s.size());
    int fs = 0;
    for(int i = 0; i < z; ++i) {
        if (s[i] == '4') {
            if (i < z / 2) fs++;
            else fs--;
        } else if (s[i] != '7') {
            return false;
        }
    }
    return fs == 0;
}

int main() {
    int N;
    string s;
    cin >> N >> s;
    printf(luck(s)?"YES\n":"NO\n");
    return 0;
}