#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e6;

struct pt {
    int x, y;
};

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

int main() {
    int n, sum = 0;
    cin >> n;
    vector <pt> data(n + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> data[i].x >> data[i].y;
        if (i >= 2 && !cw(data[i - 2], data[i - 1], data[i])) {
            sum++;
        }
    }
    cout << sum;
}