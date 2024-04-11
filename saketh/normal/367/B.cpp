#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define int long long

int N, M, P, V;
vector<int> a, b, r;
unordered_map<int, int> bset;

signed main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> P;

    for(int i=0; i<N; i++){
        cin >> V;
        a.push_back(V);
    }

    for(int i=0; i<M; i++){
        cin >> V;
        b.push_back(V);
        bset[V]++;
    }

    for(int q=0; q<P; q++){
        unordered_map<int, int> aset;
        int num = 0;

        for(int i=q; i<N; i+=P){
            int j = i - M * P;
            if(j >= 0){
                aset[a[j]]--;        
                if(aset[a[j]] < bset[a[j]]) num--;
            }

            if(aset[a[i]] < bset[a[i]]) num++;
            aset[a[i]]++;

            if((j+P)>=0 && M==num) r.push_back(j+P+1);
        }
    }

    if(!r.size()){ cout << 0 << endl; return 0; }

    sort(r.begin(), r.end());
    cout << r.size() << "\n";
    for(int v : r) cout << v << " ";
    cout << endl;
    return 0;
}