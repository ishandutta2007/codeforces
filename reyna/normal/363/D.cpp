//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 1e5 + 1e3;
int b[Maxn];
int p[Maxn];
int main(){
    int n,m,share;
    cin >> n >> m >> share;
    for(int i = 0; i < n;i++)
        cin >> b[i];
    for(int i = 0; i < m;i++)
        cin >> p[i];
    sort(b,b+n);
    sort(p,p+m);
    int ans = 0;
    int L = 0,R = min(n+1,m+1);
    while(L < R){
        int mid = (L + R) >> 1;
        long long tmp = share;
        int ptr = n-1;
        for(int i = mid-1;i > -1;--i){
            if(b[ptr] > p[i]){
                ptr--;
                continue;
            }
            tmp -= p[i]-b[ptr--];
        }
        if(tmp > -1){
            ans = max(ans,mid);
            L = mid+1;
        }else{
            R = mid;
        }
    }
    cout << ans << ' ';
    long long cnt = 0;
    for(int i = 0; i < ans;i++){
        cnt += p[i];
    }
    cout << max(cnt - share,(long long)0) << endl;
    return 0;
}