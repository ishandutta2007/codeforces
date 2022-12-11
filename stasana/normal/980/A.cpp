#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;

#define all(x) (x).begin(), (x).end()
#define f_e for_each

void main$(int testId);
bool isSystemTesting;
int testCount;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    isSystemTesting = true;
    if (strlen(__FILE__) > 41) {
        if (32[__FILE__] == 'b' &&
            33[__FILE__] == 'o' &&
            34[__FILE__] == 'k' &&
            35[__FILE__] == 'u' &&
            36[__FILE__] == 'n' &&
            37[__FILE__] == 'o' &&
            38[__FILE__] == 'p' &&
            39[__FILE__] == 'i' &&
            40[__FILE__] == 'c' &&
            41[__FILE__] == 'o') {
            isSystemTesting = false;
        }
    }

    testCount = 1;
    if (!isSystemTesting) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> testCount;
    }
}

void end() {
    if (!isSystemTesting) {
        fclose(stdin);
        fclose(stdout);
    }
}

int main() {
    start();

    for (int i = 0; i < testCount; ++i) {
        main$(i);
        if (!isSystemTesting) {
            cout << endl << "----------" << endl;
        }
    }

    end();
    return 0;
}

template<class T>
T input() {
    T result;
    cin >> result;
    return result;
}

template<class T>
void print(T value) {
    cout << value << " ";
}

void main$(int testId) {
    string s = input<string>();
    int a = 0;
    int b = 0;
    for (char i : s) {
        if (i == '-') {
            ++a;
        }
        else {
            ++b;
        }
    }
    if (b == 0 || a % b == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}