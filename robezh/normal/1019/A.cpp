#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e3 + 500;

int n,m;
int p[N], c[N];
vector<int> vote[N];

ll get(int vot){
    ll res = 0, cnt = vote[0].size();
    priority_queue<int, vector<int>, greater<int> > pque;
    for(int i = 1; i < m; i++){
        for(int j = 0; j < vote[i].size(); j++){
            if(j + vot <= vote[i].size()){
                res += vote[i][j];
                cnt ++;
            }
            else pque.push(vote[i][j]);
        }
    }
    while(cnt < vot){
        res += pque.top();
        pque.pop();
        cnt++;
    }
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> p[i] >> c[i];
        p[i]--;
        vote[p[i]].push_back(c[i]);

    }
    for(int i = 0; i < m; i++){
        if(vote[i].empty()) continue;
        sort(vote[i].begin(), vote[i].end());
    }


    ll res = (ll)1e18;
    for(int i = 1; i <= n; i++) {
        res = min(res, get(i));
    }
    cout << res << endl;


}