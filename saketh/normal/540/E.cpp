#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string.h>
using namespace std;

const int MAXN = 300005;
int bit[1000005];

int read(int k){
    int sum = 0;
    while(k > 0){
        sum += bit[k];
        k -= (k & -k);
    }
    return sum;
}

void update(int i, int v){
    while(i <= MAXN){
        bit[i]+=v;
        i += (i & -i);
    }
}

int N;
int sw[100005][2];

vector<int> allv;
unordered_map<int, int> comp;

int data[300005];

int touched(int x, int y){
    auto it1 = upper_bound(allv.begin(), allv.end(), y);
    auto it2 = lower_bound(allv.begin(), allv.end(), x);
    return it1 - it2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> sw[i][0] >> sw[i][1];
        allv.push_back(sw[i][0]);
        allv.push_back(sw[i][1]);
    }

    sort(allv.begin(), allv.end());
    allv.resize(unique(allv.begin(), allv.end()) - allv.begin());
    
    int M = allv.size();
    
    for(int i=0; i<M; i++)
        comp[allv[i]] = i;

    for(int i=1; i<=M; i++)
        data[i-1] = i;
    
    for(int i=0; i<N; i++)
        swap(data[comp[sw[i][0]]], data[comp[sw[i][1]]]);

    long long ans = 0;
    
    for(int i=0; i<M; i++){
        int vh = allv[data[i]-1];
        int sh = allv[i];

        ans += i - read(data[i]);
        if(vh+1 <= sh-1) {
            ans += sh - 1 - vh - touched(vh+1, sh-1);
        }
        else if(sh+1 <= vh-1){
            ans += vh - 1 - sh - touched(sh+1, vh-1);
        }

        update(comp[vh]+1, 1);        
    }

    cout << ans << endl;
}