#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        n >>= 1;

        if(n&1) puts("NO");
        else {
            puts("YES");
            vector <int> odd, even;
            for(int i=0, x=1; i<n; i++, x+=5) {
                if(i&1) {
                    odd.push_back(2*x-1);
                    even.push_back(2*x);
                }
                else {
                    odd.push_back(2*x+1);
                    even.push_back(2*x);
                }
            }
            for(int x : even) printf("%d ", x);
            for(int x : odd) printf("%d ", x);
            puts("");
        }
    }
}