#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    while(k--) {
        int x,y;
        scanf("%d %d", &x, &y);
        scanf("%d %d", &x, &y);
    }

    string s;
    for(int i=1; i<n; i++) s+='U';
    for(int i=1; i<m; i++) s+='L';
    for(int i=1; i<=n; i++) {
        for(int j=1; j<m; j++) {
            if(i&1) s+='R';
            else s+='L';
        }
        if(i<n) s+='D';
    }

    cout << s.size() << endl;
    cout << s << endl;
}