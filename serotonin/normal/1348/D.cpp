#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);

        vector <int> ans;
        int csum = 1, cbct = 1;
        do {
            int rem = n - csum;
            if((cbct << 1) >= rem) {
                int x = rem - cbct;
                ans.push_back(x);
                cbct += x;
                csum += cbct;
            }
            else if((cbct << 1) > rem / 2) {
                int x = rem / 2 - cbct;
                ans.push_back(x);
                cbct += x;
                csum += cbct;
            }
            else {
                ans.push_back(cbct);
                cbct += cbct;
                csum += cbct;
            }
        } while(csum < n);
        printf("%d\n", ans.size());
        for(int x : ans) printf("%d ", x);
        puts("");
    }
}