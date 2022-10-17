#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const ll MISS = 0x3f7f7f7f7f7f7f;

void fail(){
    cout << "Incorrect sequence\n";
    exit(0);
}

void solve(vector<ll> &fam){
    ll lst = -MISS, idx = -1;
    fam.push_back(MISS+1);

    for(int i=0; i<fam.size(); i++){        
        if(fam[i] == MISS) continue;
        if(fam[i] - lst - 1 < i - idx - 1) fail();            
    
        if(lst >= 0){
            for(int j=idx+1; j<i; j++)
                fam[j] = lst+(j-idx);
        }
        else if(fam[i] <= 0){
            for(int j=i-1; j>idx; j--)
                fam[j] = fam[i]-(i-j);
        }     
        else{
            int zloc = (idx+i)/2;

            if(lst + zloc - idx > 0) zloc = idx + abs(lst);
            if(i - zloc > fam[i]) zloc = i - fam[i];
            
            for(int j=idx+1; j<i; j++)
                fam[j] = j - zloc; 
        }

        lst = fam[i];
        idx = i;
    }
}

int N, K;
ll vals[200005];

int main(){
    setup();
    for(ll &x : vals) x = MISS;

    cin >> N >> K;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(s == "?") vals[i] = MISS;
        else vals[i] = atoi(s.c_str());
    }

    for(int f=0; f<K; f++){
        vector<ll> fam;
        for(int i=f; i<N; i+=K)
            fam.push_back(vals[i]);
        solve(fam);
        for(int i=f; i<N; i+=K)
            vals[i] = fam[(i-f)/K];
    }

    for(int i=0; i<N; i++)
        cout << vals[i] << " ";
    cout << endl;
}