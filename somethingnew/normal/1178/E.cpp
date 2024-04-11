#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    string ans;
    string s;
    cin >> s;
    int j = s.size() - 2;
    int i = 0;
    for (; i + 1 < j; i += 2, j -= 2) {
        //cout << i << ' ' << j << endl;
        vector<int> a(3);
        a[s[i] - 'a']++;
        a[s[i+1] - 'a']++;
        a[s[j] - 'a']++;
        a[s[j+1] - 'a']++;
        for (int k = 0; k < 3; ++k) {
            if (a[k] > 1){
                ans.push_back(k + 'a');
                break;
            }
        }
    }
    cout << ans;
    reverse(all(ans));
    if (s.size() % 4 != 0) {
        cout <<s[i];
    }
    cout << ans;
}