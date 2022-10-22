#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m;
map<string , string> h;

void work() {
    cin >> m >> n;
    for (int i = 0 ; i < n ; ++ i) {
        string A , B;
        cin >> A >> B;
        if (A.size() <= B.size())
            h[A] = h[B] = A;
        else
            h[A] = h[B] = B;
    }
    for (int i = 0 ; i < m ; ++ i) {
        string A;
        cin >> A;
        cout << h[A] << ' ';
    }
}

int main() {
    work();
    return 0;
}