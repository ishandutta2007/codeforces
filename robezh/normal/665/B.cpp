#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int order[105][105];
int item[105];

int find(int t){
    int index;
    for(int i = 0; i < k; i++){
        if(item[i] == t){
            index = i; break;
        }
    }
    for(int i = index; i > 0; i--){item[i] = item[i-1];}
    item[0] = t;

    return index+1;
}

int main(){
    int res = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) cin >> item[i];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &order[i][j]), res += find(order[i][j]);
    cout << res;

}