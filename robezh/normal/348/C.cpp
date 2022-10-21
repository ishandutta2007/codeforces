#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;
const int SQR = 317;

int n,m,q;
vector<int> nums[N];
ll heavy_add[N], base_sum[N];
ll val[N];
vector<int> heavy_occur[N], occur[N];
int heavy_id[N];
int heavy_idx[N];
int inter[N][SQR + 5];
int h_cnt = 0;

bool heavy[N];

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < n; i++) scanf("%I64d", &val[i]);
    for(int i = 0; i < m; i++){
        int k;
        scanf("%d", &k);
        while(k--){
            int a;
            scanf("%d", &a);
            a--;
            nums[i].push_back(a);
            base_sum[i] += val[a];
        }
        if(nums[i].size() > SQR){
            heavy_idx[h_cnt] = i;
            heavy_id[i] = h_cnt++;
            heavy[i] = true;
            for(auto x : nums[i]) heavy_occur[x].push_back(i);
        }
        for(auto x : nums[i]) occur[x].push_back(i);
    }
    for(int i = 0; i < n; i++){
        for(int a : heavy_occur[i]){
            for(int b : occur[i]){
                inter[b][heavy_id[a]] ++;
            }
        }
    }
    while(q--){
        getchar();
        char c;
        scanf("%c", &c);
        if(c == '?'){
            int i; scanf("%d", &i); i--;
            if(heavy[i]){
                ll res = base_sum[i];
                for(int j = 0; j < h_cnt; j++) res += 1LL * inter[i][j] * heavy_add[heavy_idx[j]];
                printf("%I64d\n", res);
            }
            else{
                ll res = 0;
                for(int idx : nums[i]) res += val[idx];
                for(int j = 0; j < h_cnt; j++) res += 1LL * inter[i][j] * heavy_add[heavy_idx[j]];
                printf("%I64d\n", res);
            }
        }
        else{
            int i, x; scanf("%d%d", &i, &x); i--;
            if(heavy[i]){
                heavy_add[i] += x;
            }
            else{
                for(int idx : nums[i]) val[idx] += x;
                for(int j = 0; j < h_cnt; j++) base_sum[heavy_idx[j]] += 1LL * inter[i][j] * x;
            }
        }
    }


}