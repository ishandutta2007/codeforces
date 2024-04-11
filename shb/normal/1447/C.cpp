#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
typedef pair<LL,int> pli;
pli A[200010];
LL W;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%lld",&N,&W);
        for (int i=1;i<=N;i++) {
            scanf("%lld", &A[i].first);
            A[i].second = i;
        }
        sort(A+1,A+N+1);
        vector<int>ans;
        LL S = 0;
        for (int i=N;i>=1;i--) {
            if (S + A[i].first > W) continue;
            S += A[i].first;
            ans.push_back(A[i].second);
        }
        if (S * 2 < W) puts("-1");
        else {
            printf("%d\n",ans.size());
            for (int i=0;i<ans.size();i++) {
                printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
            }
        }
    }
}