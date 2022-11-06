#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

typedef pair <int,int> pii;
#define x first
#define y second

int a[sz], b[sz];
bitset <sz> ra, rb;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]), ra[i]=0, rb[i]=0;

        for(int i=1; i<=n; i++) {
            b[i]=max(b[i-1], a[i]);
            ra[a[i]] ? b[i]=n+1 : ra[a[i]]=1;
        }

        vector <pii> on;
        for(int i=n, j=0; i>1; i--) {
            j=max(j, a[i]);
            rb[a[i]] ? j=n+1 : rb[a[i]]=1;
            if(j==n-i+1 && b[i-1]==i-1) on.push_back({i-1,j});
        }

        printf("%d\n", on.size());
        for(auto v : on) printf("%d %d\n", v.x, v.y);
    }
}