#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        PP p[100002];
        for(int i = 0; i < n; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            p[i] = PP(P(l, r), i);
        }
        sort(p, p + n);
        bool f[100005]{0};
        f[p[0].second] = true;
        int r = p[0].first.second;
        for(int i = 1; i < n; i++){
            if(p[i].first.first > r) break;
            r = max(r, p[i].first.second);
            f[p[i].second] = true;
        }
        if(f[p[n - 1].second]) printf("-1\n");
        else{
            for(int i = 0; i < n; i++){
                if(f[i]) printf("1 ");
                else printf("2 ");
            }
            printf("\n");
        }
    }
}