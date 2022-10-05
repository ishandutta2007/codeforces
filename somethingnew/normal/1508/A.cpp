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
void solve(){
    int n;
    cin >> n;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    string sans;
    int i1 = 0, i2 = 0, i3 = 0;
    for (int i = 0; i < 3 * n; ++i) {
        int cnt0 = 0, cnt1 = 0;
        if (i1 != n * 2) {
            cnt0 += (s1[i1] == '0');
            cnt1 += (s1[i1] == '1');
        }
        if (i2 != n * 2) {
            cnt0 += (s2[i2] == '0');
            cnt1 += (s2[i2] == '1');
        }
        if (i3 != n * 2) {
            cnt0 += (s3[i3] == '0');
            cnt1 += (s3[i3] == '1');
        }
        if (cnt0 == cnt1) {
            int c = -1;
            char a = '1';
            if (i1 != n * 2) {
                if (i1 > c)
                    a = s1[i1];
                c = max(c, i1);
            }
            if (i2 != n * 2) {
                if (i2 > c)
                    a = s2[i2];
                c = max(c, i2);
            }
            if (i3 != n * 2) {
                if (i3 > c)
                    a = s3[i3];
                c = max(c, i3);
            }
            if (c != -1) {
                if (a == '1')
                    cnt1++;
                else
                    cnt0++;
            }

        }
        if (cnt0 > cnt1)
            sans.push_back('0');
        else
            sans.push_back('1');
        if (i1 != n * 2) {
            if ((cnt0 > cnt1) ^ (s1[i1] == '1')) {
                i1++;
            }
        }
        if (i2 != n * 2) {
            if ((cnt0 > cnt1) ^ (s2[i2] == '1')) {
                i2++;
            }
        }
        if (i3 != n * 2) {
            if ((cnt0 > cnt1) ^ (s3[i3] == '1')) {
                i3++;
            }
        }
    }
    cout << sans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}