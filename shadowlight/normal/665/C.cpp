#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int size = 1, l;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            if (size == 1) {
                l = i - 1;
            }
            size++;
        } else if (size != 1) {
            char spec;
            if (s[l] != 'a' && s[l + size] != 'a') spec = 'a';
            else if (s[l] != 'b' && s[l + size] != 'b') spec = 'b';
            else spec = 'c';
            for (int k = l + 1; k < l + size; k += 2) {
                s[k] = spec;
            }
            l = -1;
            size = 1;
        }
    }
    char spec;
    if (size != 1) {
        if (s[l] != 'a') spec = 'a'; else spec = 'b';
    }
    for (int k = l + 1; k < l + size; k += 2) {
        s[k] = spec;
    }
    cout << s;
}