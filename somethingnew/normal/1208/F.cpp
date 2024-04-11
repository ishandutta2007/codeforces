#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include "queue"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;

int MXC = (1 << 21);
vector<int> nums(MXC, 0);
void add(int x) {
    if (nums[x] == 2)
        return;
    queue<pair<int, int>> a;
    a.push({x, 0});
    while (!a.empty()) {
        int v = a.front().first, k = a.front().second;
        a.pop();
        if (nums[v] == 2)
            continue;
        nums[v]++;
        for (int i = k; i < 21; ++i) {
            if (v & (1 << i))
                a.push({v ^ (1 << i), i + 1});
        }
    }
}
int findmx(int x) {
    int a2 = (MXC - 1) ^ x;
    int num2 = 0;
    for (int i = 20; i >= 0; --i) {
        if ((1 << i) & a2) {
            if (nums[num2 ^ (1 << i)] == 2)
                num2 |= (1 << i);
        }
    }
    return x + num2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    int MXC = (1 << 21);
    //cout << MXC << endl;
    vector<int> n1;
    cin >> n;
    int findans = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        n1.push_back(b);
    }
    reverse(all(n1));
    int cn = 0;
    for (auto b : n1) {
        cn++;
        if (cn > 2)
            findans = max(findans, findmx(b));
        add(b);
    }
    cout << findans;
}