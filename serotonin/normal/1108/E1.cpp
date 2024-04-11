#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=305, inf=2e9;

vector <int> ans[sz];
vector <int> a,now;
pair <int,int> p[sz];

int main()
{
    int i,j,n,m;
    cin >> n >> m;
    for(i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    for(i=0; i<m; i++) scanf("%d %d", &p[i].first, &p[i].second), p[i].first--, p[i].second--;
    int fin=-inf,finpos;
    for(i=0; i<n; i++) {
        now=a;
        for(j=0; j<m; j++) {
            if(p[j].first<=i && i<=p[j].second) {
                for(int k=p[j].first; k<=p[j].second; k++) {
                    now[k]--;
                }
                ans[i].push_back(j);
            }
        }
        int mx=-inf;
        for(j=0; j<n; j++) mx=max(mx,now[j]);
        int dif=mx-now[i];
        if(dif>fin) {
            fin=dif;
            finpos=i;
        }
    }
    printf("%d\n", fin);
    printf("%d\n", ans[finpos].size());
    for(i=0; i<ans[finpos].size(); i++) printf("%d ", ans[finpos][i]+1);
}