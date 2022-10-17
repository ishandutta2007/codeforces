#include<iostream>
#include<algorithm>
using namespace std;

int N, M, B, K, w, nm;
long long cost[105];
pair<long long, int> moni[105];
int mask[105];

long long ans = 1LL<<62;
short dp1[1<<20 + 5];
int dp2[1<<20 + 5];

long long lookup(int idx){
    long long ret = 0;
    ret += 1000000000LL * dp1[idx];
    return ret + dp2[idx];
}


void upd(int idx, int msk, long long cost){
    if(dp1[idx] == 500) return;
    int tar = idx | msk;
    long long tarv = lookup(tar);
    long long cand = lookup(idx) + cost;
    if(cand >= tarv) return;
    dp1[tar] = cand / 1000000000;
    dp2[tar] = cand % 1000000000;
}

void inf(int idx){
    dp1[idx] = 500;
}

int main(){
    cin >> N >> M >> B;

    for(int i=0; i<N; i++){
        cin >> cost[i] >> nm >> K;
        moni[i] = make_pair(nm, i);
        for(int k=0; k<K; k++){
            cin >> w;
            mask[i] |= 1 << (w-1);
        }
    }
        
    sort(moni, moni+N);
    
    dp1[0] = dp2[0] = 0;
    for(int i=1; i<(1<<M); i++)
        inf(i);
    
    for(int p=0; p<N; p++){
        for(int i=0; i<(1<<M); i++){
            upd(i, mask[moni[p].second], cost[moni[p].second]);
        }
    
        if(dp1[(1<<M)-1] != 500){
            ans = min(ans, moni[p].first*B + lookup(((1<<M)-1)));
        }
    }
    
    if(ans == 1LL<<62) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}