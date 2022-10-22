#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int TC, N;
int A[505050];
int ans[505050], num;
int S[505050], T;
vector<pii> Seg;

int main(){
    scanf("%d", &TC);
    while (TC--){
        scanf("%d", &N);
        Seg.clear();
        for (int i=1; i<=N; i++) {
            scanf("%d", &A[i]);
            if (A[i] != -1) Seg.push_back(pii(i, A[i]));
            ans[i] = 0;
        }
        sort(Seg.begin(), Seg.end(), [&](pii X, pii Y){
            if (X.second == Y.second) return X.first < Y.first;
            return X.second > Y.second;
        });
        ans[N+1] = 1;
        num=N, T=1;
        bool tf = true;
        for (int i=0; i<(int)Seg.size(); i++){
            if (!ans[Seg[i].second]) ans[Seg[i].second] = num--;
            if (!ans[Seg[i].first]) ans[Seg[i].first] = num--;
            while (S[T-1] >= Seg[i].second && T>1) T--;
            if (S[T-1] > Seg[i].first){
                tf = false;
                break;
            }
            S[T++] = Seg[i].first;
        }
        if (tf){
            for (int i=1; i<=N; i++){
                if (ans[i]) printf("%d ", ans[i]);
                else{
                    printf("%d ", num);
                    num--;
                }
            }
            printf("\n");
        }
        else puts("-1");
    }
    return 0;
}