#include <iostream>
#include <string.h>
using namespace std;

int N, v[100005], blen[100005], res[100005];
int mlen = 0, nuse[100005], high[100005];
bool use[100005];

void add(int ev, int len){
    while(ev <= 100000){
        blen[ev] = max(blen[ev], len);
        ev += (ev & -ev);
    }
}

int read(int k){
    int ans = 0;
    while(k > 0){
        ans = max(ans, blen[k]);
        k -= (k & -k);
    }
    return ans;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        res[i] = 1 + read(v[i]-1);
        add(v[i], res[i]);
        mlen = max(mlen, res[i]);
    }
    
    high[mlen+1] = 100005;
    for(int i=N-1; i>=0; i--)
        if(v[i] < high[res[i]+1]){
            use[i] = true;
            nuse[res[i]]++;
            high[res[i]] = max(high[res[i]], v[i]);
        }

    for(int i=0; i<N; i++)
        if(!use[i]) cout << 1;
        else if(nuse[res[i]] > 1) cout << 2;
        else cout << 3;

    cout << endl;
    return 0;
}