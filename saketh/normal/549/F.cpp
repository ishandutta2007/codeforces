#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 300005;
const int MAXK = 1000005;

int N, K;
int task[MAXN];
int ord[MAXN];

int lnext[MAXN];
int lprev[MAXN];
int pref[MAXN];
vector<int> ps[MAXK];

int occ(int i, int j, int v){
    if(i>j) return 0;
    return upper_bound(ps[v].begin(), ps[v].end(), j)
         - lower_bound(ps[v].begin(), ps[v].end(), i);
}

ll calc(int idx){
    ll res = 0;
    if(idx-lprev[idx] <= lnext[idx]-idx)
        for(int left=lprev[idx]+1; left<=idx; left++)
            res += occ(idx, lnext[idx]-1, (pref[left-1]+task[idx])%K);    
    else
        for(int right=idx; right<=lnext[idx]-1; right++)
            res += occ(lprev[idx], idx-1, (pref[right]-(task[idx]%K)+K)%K);
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);

    cin >> N >> K;
    
    ps[0].push_back(0);
    lnext[0] = 1;
    lprev[N+1] = N;

    for(int i=1; i<=N; i++){
        cin >> task[i];
        pref[i] = (pref[i-1] + task[i]) % K;
        ps[pref[i]].push_back(i);
        lprev[i] = i-1;
        lnext[i] = i+1;
    }

    for(int i=0; i<N; i++)
        ord[i] = i+1;    
    sort(ord, ord+N, [](int i, int j)->bool{ return task[i] < task[j]; });

    ll ans = 0;
    for(int i=0; i<N; i++){
        ans += calc(ord[i]);
        int pv = lprev[ord[i]], nx = lnext[ord[i]];
        lnext[pv] = nx, lprev[nx] = pv;
    }
    cout << ans-N << endl;
}