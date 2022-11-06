#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!i && !j) printf("W");
                else printf("B");
            }
            puts("");
        }
    }
}