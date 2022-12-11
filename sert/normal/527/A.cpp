#include <vector>
#include <map>
#include <fstream>
#include <list>
#include <string>
#include <climits>
#include <set>
#include <iostream>

using namespace std;

long long a, b, c;

int main() {

    cin >> a >> b;

    while (a != b) {
        if (a < b)
            swap(a, b);
        if (b == 0)
            break;
        c += a / b;
        a %= b;
    }

    cout << c;

    return 0;
}