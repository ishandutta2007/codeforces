#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = (int)4e5 + 500;

ll res = 0;
int n;
int bit[MAXN];
int num[MAXN];
vector<int> V[MAXN];

int get(int i){
    int ans = 0;
    while(i){ans += bit[i]; i -= (i&-i);}
    return ans;
}

int add(int i){
    while(i < MAXN){bit[i] += 1; i += (i&-i);}
}

int main() {
    fill(bit, bit+MAXN, 0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
        if(num[i] >= n) V[n].push_back(i);
        else V[num[i]].push_back(i);
    }
    for(int i = n; i >= 1; i--){
        for(int k : V[i]){add(k);}
        int q = get(min(num[i], n));
        if(num[i] >= i) q--;
        res += q;
    }
    cout << res/2;



}