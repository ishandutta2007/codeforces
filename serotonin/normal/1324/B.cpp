#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5005;

vector <int> a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            a[x].push_back(i);
        }

        bool yes=0;

        for(int i=1; i<=n; i++) {
            sort(a[i].begin(), a[i].end());
            if(!a[i].size()) continue;

            if(a[i][0]+1 < a[i].back()) yes=1;
            a[i].clear();
        }

        if(yes) puts("YES");
        else puts("NO");
    }
}