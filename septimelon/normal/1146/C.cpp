#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    int t;
    cin >> t;
    int k = 1;
    bool va;
    queue<int> a;
    queue<int> b;

    int ak, bk;
    int cur = 1;
    int curmax = 0;
    int input;
    for (int q = 0; q < t; q++) {
        k = 1;
        curmax = 0;
        cin >> n;
        while (k < n) {
            ak = 0;
            bk = 0;
            cur = 1;
            va = true;
            while (cur <= n) {
                if (va) {
                    a.push(cur);
                    ak++;
                }
                else {
                    bk++;
                    b.push(cur);
                }
                if (cur % k == 0)
                    va = !va;
                cur++;
            }
            cout << ak << " " << bk;
            while (!a.empty()) {
                cout << " " << a.front();
                a.pop();
            }
            while (!b.empty()) {
                cout << " " << b.front();
                b.pop();
            }
            cout << endl;
            fflush(stdout);
            cin >> input;
            if (input == -1)
                return 0;
            if (input > curmax)
                curmax = input;
            k *= 2;
        }
        cout << "-1 " << curmax << endl;
        fflush(stdout);
    }
    return 0;
}