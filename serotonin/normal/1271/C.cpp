#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

#define x first
#define y second

typedef pair <int,int> pii;

pii p[sz];

int main()
{
    int n;
    cin >> n;
    int sx,sy;
    cin >> sx >> sy;
    for(int i=0; i<n; i++) scanf("%d %d", &p[i].x, &p[i].y);

    int a[4]={0};
    for(int i=0; i<n; i++) {
        if(p[i].x < sx) a[0]++;
        if(p[i].x > sx) a[1]++;
        if(p[i].y < sy) a[2]++;
        if(p[i].y > sy) a[3]++;
    }

    int ans=0;
    for(int i=0; i<4; i++) ans=max(ans, a[i]);

    for(int i=0; i<4; i++) {
        if(ans==a[i]) {
            printf("%d\n", ans);
            if(!i) printf("%d %d\n", sx-1, sy);
            else if(i==1) printf("%d %d\n", sx+1, sy);
            else if(i==2) printf("%d %d\n", sx, sy-1);
            else printf("%d %d\n", sx, sy+1);
            break;
        }
    }
}