#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> tick[10000];

int out[8];
void print(int a, int b) {
    int r = 1e4 * a + b;
    for (int i = 0; i < 8; i++) {
        out[i] = r % 10;
        r /= 10;
    }

    for (int i = 7; i >= 0; i--)
        cout << out[i];
    cout << "\n";
}

int num[4];
vector<int> make(int i, int j) {
    if(i == j) return vector<int>(1, num[i]);

    vector<int> res;

    for (int k = i; k < j; k++) {
        vector<int> left = make(i, k);
        vector<int> right = make(k+1, j);

        for (int a : left)
            for (int b : right) {
                res.push_back(a * b);
                res.push_back(a + b);
                res.push_back(a - b);
            }
    }

    int all = 0;
    for (int k = i; k <= j; k++)
        all = 10 * all + num[k];
    res.push_back(all);

    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    return res; 
}

int use[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int half = 0; half < 1e4; half++) {
        int temp = half;
        for (int dig = 0; dig < 4; dig++) {
            num[3 - dig] = temp % 10;
            temp /= 10;
        }

        vector<int> all = make(0, 3);
        for (int res : all) {
            if(res < 0 || res >= 1e4) continue;
            tick[res].push_back(half);
        }
    } 

    int K, M;
    cin >> K >> M;

    for (int front = 0; front < 1e4; front++) {
        if(front <= K) {
            for (int way : tick[K - front]) {
                print(front, way);
                use[way] = front;
                M--;
                if(!M) return 0;
            }
        }
        if(front >= K) {
            for (int way : tick[front - K]) {
                if(use[way] == front) continue;
                print(front, way);
                M--;
                if(!M) return 0;
            }
        }
    }
    return 0;
}