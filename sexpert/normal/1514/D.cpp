#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
#define lolol long long
#define endl '\n'
#define BLOCK 555

struct query{
    int l, r, i;
};

query Q[300005];
int ar[300005], freq[300005], ans[300005];
int freqOfFreq[300005];
int curr_max = 0;

bool comp(query a, query b){
    if(a.l/BLOCK != b.l/BLOCK)
        return a.l/BLOCK < b.l/BLOCK;
    return a.r < b.r;
}

void add(int pos){
    int pre = freq[ar[pos]];
    freq[ar[pos]]++;
    int curr = freq[ar[pos]];
    if(pre != 0) freqOfFreq[pre]--;
    freqOfFreq[curr]++;
    if(curr > curr_max){
        curr_max = curr;
    }
}

void remove(int pos){
    int pre = freq[ar[pos]];
    freq[ar[pos]]--;
    int curr = freq[ar[pos]];
    freqOfFreq[pre]--;
    freqOfFreq[curr]++;
    if(curr < curr_max){
        while(freqOfFreq[curr_max] == 0){
            curr_max--;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    for(int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }
    sort(Q, Q+q, comp);
    int ML = 0, MR = -1;
    for(int i = 0; i < q; i++){
        int L = Q[i].l, R = Q[i].r;
        while(ML > L)
            ML--, add(ML);
        while(MR < R)
            MR++, add(MR);

        while(ML < L)
            remove(ML), ML++;
        while(MR > R)
            remove(MR), MR--;

        int total = R-L+1;
        int rem = total-curr_max;
        int half = (total+1)/2;
        if(curr_max <= half)
            ans[Q[i].i] = 1;
        else
            ans[Q[i].i] = total-2*rem;
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}