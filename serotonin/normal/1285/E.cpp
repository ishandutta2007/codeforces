#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+5, INF=2e9;

typedef pair <int,int> pii;
#define x first
#define y second

pii seg[sz];
int d[sz], one[sz], zero[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        vector <pii> a;
        a.push_back({-INF,0});
        for(int i=1; i<=n; i++) {
            int l,r;
            scanf("%d %d", &l, &r);
            a.push_back({l,-i});
            a.push_back({r,i});
        }

        sort(a.begin(), a.end());

        for(int i=1; i<=2*n; i++) {
            if(a[i].y < 0) seg[0-a[i].y].x = i;
            else seg[a[i].y].y = i;
        }

        for(int i=1, j=0, k=0, l=0; i<=2*n; i++) {
            if(a[i].y < 0) j++;
            else j--;
            d[i]=j;

            if(j==1) k++;
            one[i]=k;

            if(!j) l++;
            zero[i]=l;
        }

        int ans=0;
        for(int i=1; i<=n; i++) {
            int l=seg[i].x, r=seg[i].y;

            int now=0;
            now += zero[l-1];
            now += one[r-1] - one[l];
            now += zero[2*n] - zero[r];

            ans=max(ans,now);
        }

        printf("%d\n", ans);
    }
}