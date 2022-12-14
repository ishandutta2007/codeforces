#include <iostream>
using namespace std;
int n, f[1005][1005];
string s;

int main()
{
    cin >> n >> s;
    for(int i=n-1; i>=0; --i) {
        for(int j=i; j<n; ++j) {
            f[i][j] = f[i+1][j] + 1;
            for(int w=i+1; w<=j; ++w)
            if (s[i] == s[w]) f[i][j] = min(f[i][j], f[i+1][w-1] + f[w][j]);
        }
    }
    cout << f[0][n-1];
}