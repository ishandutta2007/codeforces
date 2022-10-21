#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MAXN = (int)1e6 + 500;


int n;
ll bit[2][MAXN];
P p[MAXN];

ll get(int t, int i){
    ll ans = 0;
    while(i){ans += bit[t][i]; i -= (i&-i);}
    return ans;
}

ll add(int t, int i, int val){
    while(i < MAXN){bit[t][i] += val; i += (i&-i);}
}

int main(){
    for(int i = 0; i < 2; i++) fill(bit[i], bit[i]+MAXN, 0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i].first) , p[i].second = i;
    sort(p+1, p + n+1, greater<P>());
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += get(1, p[i].second);
        add(1,p[i].second, (int)get(0,p[i].second));
        add(0,p[i].second,1);
    }
    cout << res << endl;

}