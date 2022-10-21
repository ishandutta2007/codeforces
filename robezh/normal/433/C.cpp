#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int num[100050];
vector<int> V[100050];
ll tosum = 0;
ll sum[100050];


int main(){
    fill(sum, sum+100050, 0);
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++) scanf("%d", &num[i]);
    for(int i = 0; i < m; i++){
        if(i-1 >= 0 && num[i-1] != num[i]) V[num[i]].push_back(num[i-1]), sum[num[i]] += abs(num[i]-num[i-1]);
        if(i+1 < m && num[i+1] != num[i]) V[num[i]].push_back(num[i+1]), sum[num[i]] += abs(num[i+1]-num[i]);
    }
    for(int i = 1; i < m; i++) tosum += abs(num[i] - num[i-1]);
    ll res = (ll)1e18;
    for(int i = 1; i <= n; i++){
        if(V[i].size() == 0) continue;
        sort(V[i].begin(), V[i].end());
        ll isum = 0, piv = V[i][(V[i].size()-1)/2];
        for(int x : V[i]) isum += abs(x - piv);
        //cout << "i = " << i << endl;
        //cout << tosum << " " << sum[i] << " " << isum << endl;
        res = min(res, tosum - sum[i] + isum);
    }
    if(res == (ll)1e18) res = 0;
    cout << res;

}