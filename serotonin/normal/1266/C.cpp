#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    int n,m;
    cin >> n >> m;
    if(n==1 && m==1) puts("0");
    else if(m==1) {
        for(int i=0; i<n; i++) printf("%d\n", 2+i);
    }
    else {
        for(int i=0; i<m; i++) printf("%d ", 2+i);
        puts("");
        for(int j=1; j<n; j++) {
            for(int i=0; i<m; i++) printf("%d ", (2+i)*(m+1+j));
            puts("");
        }
    }
}