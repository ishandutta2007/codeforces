#include <bits/stdc++.h>
using namespace std;

int n,m,k;
multiset<int> S[5];
int num[100050][5];

int getmax(int pos){
    int mx = 0;
    for(int j = 0; j < m; j++){
        mx += max(num[pos][j], S[j].empty() ? 0 : *(--S[j].end()));
    }
    return mx;
}

//int getmax(){
//    int mx = 0;
//    for(int j = 0; j < m; j++)
//        mx += *(--S[j].end());
//    return mx;
//}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &num[i][j]);
    int res = 0, pos = -1;
    int rmx[5]={0,0,0,0,0};
    for(int i = 0; i < n; i++) {
        while (pos+1 < n && getmax(pos + 1) <= k){
            pos++;
            for(int j = 0; j < m; j++) S[j].insert(num[pos][j]);
        }
        if(S[0].size() > res){
            res = S[0].size();
            for(int j = 0; j < m; j++) rmx[j] = *(--S[j].end());
        }
        if (S[0].size() == 0) {
            pos++;
            continue;
        }
        for (int j = 0; j < m; j++) S[j].erase(num[i][j]);
    }
    for(int i = 0; i < m; i++){
        cout << rmx[i] << " ";
    }

    return 0;
}