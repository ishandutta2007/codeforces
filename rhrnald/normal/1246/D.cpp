#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>








#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()








using namespace std;








typedef long long ll;
typedef pair<int,int> pii;








const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;








const int N = 1000001;
int n,m;








vector<int> v[N];
int p[N];
int s[N];
int h[N];








vector<int> ans;
vector<int> L;








bool cmp(int x, int y) {
        return h[x]<h[y];
}
int dfs(int cur) {
        h[cur]=0;
        for(int nxt : v[cur]) h[cur]=max(h[cur], dfs(nxt)+1);
        return h[cur];
}
int main(void){
        scanf("%d", &n);
        for(int i=1; i<n; i++) scanf("%d", p+i);
        for(int i=1; i<n; i++) v[p[i]].push_back(i);
        dfs(0);
        int cur=0;
        while(sz(v[cur])) {
                L.push_back(cur);
                if(sz(v[cur])==1) {cur=v[cur][0]; continue;}
                
                sort(all(v[cur]), cmp);
                int nxt=v[cur][0];
                for(int i=sz(v[cur])-1; i>=1; i--) {
                        int x=v[cur][i-1];
                        ans.push_back(v[cur][i]);
                        v[x].push_back(v[cur][i]);
                        h[x]+=h[v[cur][i]]+1;
                }
                cur=v[cur][0];
        }
        L.push_back(cur);








        for(int e : L) printf("%d ", e);
        printf("\n%d\n", sz(ans));
        for(int i=sz(ans)-1; i>=0; i--) printf("%d ", ans[i]);
}