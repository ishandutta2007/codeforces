#include <iostream>

using namespace std;
long long t,n,k,res, f[55];
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        fill(f, f+n+1, 0);
        int i=0;
        for(i=0; i<n; i++) if (s[i] == '*') break;
        if (i==n) { cout << 0; continue; }
        res = f[i] = 1;
        for(int j=i+1; j<n; j++) if (s[j] == '*') {
            for(int w=max(0ll,j-k); w<j; w++) if (s[w] == '*') {
                f[j] = f[w] + 1;
                break;
            }
            res = f[j];
        }
        cout << res << '\n';
    }
}