#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
                int n, m;
                cin >> n >> m;
                int sum = 0;
                for (int j = 0; j < n; ++j) {
                        int x;
                        cin >> x;
                        sum += x;
                }
                if (sum == m)
                        cout << "YES\n";
                else
                        cout << "NO\n";
        }
        return 0;
}