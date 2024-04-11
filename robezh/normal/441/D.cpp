#include <bits/stdc++.h>
using namespace std;

int n;
int u[3005];
int num[3005], loc[3005];
int m;
set<int> S;

int find(int i){return u[i] == i ? i : u[i] = find(u[i]);}
void unite(int i, int j){int fi = find(i), fj = find(j); u[max(fi,fj)] = min(fi,fj);}
int same(int i, int j){return find(i) == find(j);}
void exch(int i, int j){int k = num[i]; num[i] = num[j], num[j] = k;}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i], loc[num[i]] = i;
    cin >> m;
    for(int i = 1; i <= n; i++) u[i] = i;

    for(int i = 1; i <= n; i++){unite(i, num[i]);}
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(u[i] == i) cnt++, S.insert(i);
    }
    cnt = n - cnt;
    if(cnt == m){printf("0\n"); return 0;}
    if(cnt < m){
        printf("%d\n", m-cnt);
        int piv = *S.begin(); S.erase(S.begin());
        while(cnt++ < m){
            cout << piv << " " << *S.begin() << endl;
            S.erase(S.begin());
        }
    }
    else{
        printf("%d\n", cnt-m);
        while(cnt-- > m){
            for(int i = 1; i <= n; i++){
                if(num[i] != i){
                    int cur = num[i], sma = cur;
                    while(cur != i){sma = min(cur, sma); cur = num[cur];}
                    cout << i << " " << sma << endl;
                    exch(i, sma);
                    break;
                }
            }
        }
    }


    return 0;
}