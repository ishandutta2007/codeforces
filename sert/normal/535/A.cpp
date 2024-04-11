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
    if (n == 0) ext("zero");
    if (n == 10) ext("ten");
    if (n == 11) ext("eleven");
    if (n == 12) ext("twelve");
    if (n == 13) ext("thirteen");
    if (n == 14) ext("fourteen");
    if (n == 15) ext("fifteen");
    if (n == 16) ext("sixteen");
    if (n == 17) ext("seventeen");
    if (n == 18) ext("eighteen");
    if (n == 19) ext("nineteen");
    if (n < 10) ext(d[n]);
    if (n % 10 == 0) ext(t[n / 10]);
    cout << t[n / 10] + "-" + d[n % 10];
    return 0;
}