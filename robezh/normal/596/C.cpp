#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int base = 100000;

int n;
P p[100050];
int cnt[200050];
vector<P> V[200050];
vector<int> x[100050],y[100050];
P rp[100050];
int w[100050];

int main(){
    fill(cnt, cnt+200050, 0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &p[i].first, &p[i].second);
        int dif = p[i].second - p[i].first;
        V[base + dif].push_back(p[i]);
    }
    for(int i = 0; i < n; i++) scanf("%d", &w[i]), cnt[w[i]+base]++;
    for(int i = 0; i <= base*2; i++) if(V[i].size() != cnt[i]) return !printf("NO");
    fill(cnt, cnt+200050, 0);
    for(int i = 0; i <= base*2; i++) sort(V[i].begin(), V[i].end());
    for(int i = 0; i < n; i++){
        P p = V[w[i]+base][cnt[w[i]+base]++];
        rp[i].first = p.first, rp[i].second = p.second;
    }

    for(int i = 0; i < n; i++){
        int xi = rp[i].first, yi = rp[i].second;
        int xpv = x[yi].empty() ? -1 : x[yi].back(), ypv = y[xi].empty() ? -1 : y[xi].back();
        if(xi < xpv || yi < ypv) return !printf("NO");
        x[yi].push_back(xi);
        y[xi].push_back(yi);
    }
    printf("YES\n");
    for(int i = 0; i < n; i++){
        printf("%d %d\n", rp[i].first, rp[i].second);
    }


}