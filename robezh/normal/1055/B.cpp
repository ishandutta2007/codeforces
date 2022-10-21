#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
typedef long long ll;

int n, q;
ll l;
ll num[N];
int u[N];
int cur;

int find(int i){
    return u[i] == i ? i : u[i] = find(u[i]);
}

void unite(int i, int j){
    i = find(i), j = find(j);
    if(i == j) return ;
    u[i] = j;
    cur--;
}

int main(){
    for(int i = 0; i < N; i++) u[i] = i;

    scanf("%d%d%I64d", &n, &q, &l);
    cur = 0;
    for(int i = 0; i < n; i++){
        scanf("%I64d", &num[i]);
        if(num[i] > l){
            cur++;
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(num[i] > l && num[i+1] > l) unite(i, i+1);
    }


    for(int i = 0; i < q; i++){
        int x;
        scanf("%d", &x);
        if(x == 0){
            printf("%d\n", cur);
        }
        else{
            int j, d;
            scanf("%d%d", &j, &d);
            j--;
            ll ori = num[j];
            num[j] += d;
            if(ori <= l && num[j] > l){
                cur++;
                if(j - 1 >= 0 && num[j-1] > l) unite(j-1, j);
                if(j + 1 < n && num[j+1] > l) unite(j, j+1);
            }
        }
    }

}