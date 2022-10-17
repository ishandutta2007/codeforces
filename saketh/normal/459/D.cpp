#include<iostream>
#include<map>
using namespace std;

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
    while(i <= 1000000){
        bit[i]+=v;
        i += (i & -i);
    }
}

int N;
int val[1000005];
int lquery[1000005];
int rquery[1000005];
map<int, int> occ1, occ2;

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> val[i];

    for(int i=0; i<N; i++){
        occ1[val[i]]++;
        lquery[i] = occ1[val[i]];
    }
    
    for(int i=N-1; i>=0; i--){
        occ2[val[i]]++;
        rquery[i] = occ2[val[i]];
    }
    
    long long ans = 0;
    for(int i=0; i<N; i++){
        ans += i - read(rquery[i]);
        update(lquery[i], 1);
    }
    
    cout << ans << endl;
    return 0;
}