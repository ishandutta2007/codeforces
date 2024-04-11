//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 123;
long long p[Maxn];
pair<long long,long long> fig[Maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> fig[i].second >> fig[i].first;
    }
    sort(fig,fig+n);
    int k;
    cin >> k;
    k++;
    p[0] = 0;
    p[k] = (long long)1 << 60;
    for(int i = 1; i < k;i++){
        cin >> p[i];
    }
    long long f = 0;
    long long cnt = 0;
    long long ans = 0;
    for(int i = 0; i < n;i++){
        long long K = fig[i].second;
        while(K){
            cerr << K << endl;
            long long tmp = cnt;
            tmp += K;
            if(p[f+1] <= tmp){
                tmp = p[++f];
                ans += f * (tmp - cnt) * fig[i].first;
                K -= (tmp - cnt);
            }else{
                ans += (f + 1) * (K) * fig[i].first;
                K = 0;
            }
            cnt = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}