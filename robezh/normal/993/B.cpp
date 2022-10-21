#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
int pa[15],pb[15];

int connec(int x, int y){
    int a1 = max(x/10, x%10), a2 = min(x/10, x%10);
    int b1 = max(y/10, y%10), b2 = min(y/10, y%10);
    if((a1 == b1) && (a2 != b2) || a1 == b2) return a1;
    if((a2 == b2) && (a1 != b1) || a2 == b1) return a2;
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        pa[i] = 10 * a + b;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        pb[i] = 10 * a + b;
    }
    int tcnt = 0;
    int now = 0;
    set<int> possi;
    for(int i = 0; i < n; i++){
        set<int> S;
        for(int j = 0; j < m; j++){
            int such = connec(pa[i], pb[j]);
            if(such >= 0) {
                S.insert(such);
                possi.insert(such);
            }
        }
        if(S.size() > 1) return !printf("-1");
    }
    for(int j = 0; j < m; j++){
        set<int> S;
        for(int i = 0; i < n; i++){
            int such = connec(pa[i], pb[j]);
            if(such >= 0){
                S.insert(such);
                possi.insert(such);
            }
        }
        if(S.size() > 1) return !printf("-1");
    }
    if(possi.size() == 1) return !printf("%d", *possi.begin());
    return !printf("0");
}