#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
    long long n, b;
    cin >> n >> b;
    queue <long long> q;
    long long time = 0, size = 0;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        while (t1 >= time && size > 0) {
            long long v = q.front();
            q.pop();
            if (v == -1) cout << -1 << " "; else {
                time += v;
                cout << time << " ";
                size--;
            }
        }
        if (t1 >= time) {
            time = t1 + t2;
            cout << time << " ";
        } else if (size < b) {
            q.push(t2);
            size++;
        } else q.push(-1);

    }
    while (q.size() != 0) {
        int v = q.front();
            q.pop();
            if (v == -1) cout << -1 << " "; else {
                time += v;
                cout << time << " ";
            }
    }
}