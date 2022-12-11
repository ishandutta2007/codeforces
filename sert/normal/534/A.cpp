#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

void ext(string s) {
    cout << s;
    exit(0);
}

const string t[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const string d[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) ext("1\n1");
    if (n == 3) ext("2\n1 3");
    cout << n << "\n";
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    return 0;
}