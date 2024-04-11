#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, tag[5005], score[5005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> tag[i];
        for(int i=0; i<n; i++) cin >> score[i];
        vector<long long> d(n,0);
        for(int i=0; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if (tag[i] == tag[j]) continue;
                long long di = d[i], dj = d[j], val = abs(score[i] - score[j]);
                d[i] = max(d[i], dj + val);
                d[j] = max(d[j], di + val);
            }
        }
        cout << *max_element(d.begin(), d.end()) << '\n';
    }
}