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
        for(int i=2; ; i++) {
            int x = 1<<i;
            x--;
            if(n%x==0) {
                printf("%d\n", n/x);
                break;
            }
        }
    }
}