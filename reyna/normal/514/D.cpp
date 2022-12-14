//In the name of God
#include <iostream>
using namespace std;
const long long Maxn = 2e5 + 1e3;
const long long Maxm = 6;
const long long LOG = 22;
long long arr[Maxn][Maxm];
long long Max[Maxm][Maxn][LOG];
long long ans[Maxm];
long long n,m,k;
bool check(long long x){
    for(long long i = 0; i < m;i++)
        ans[i] = 0;
    if(!x)
        return 1;
    long long lg = 0;
    for(long long i = 0; i < LOG;i++){
        if((1 << i) <= x)
            lg = i;
    }
//  cerr << x << '!' << lg << endl;
    for(long long i = 0; i < n-x+1;i++){
        long long cnt = 0;
        for(long long j = 0; j < m;j++){
            ans[j] = max(Max[j][i][lg],Max[j][i+x-(1 << lg)][lg]);
            cnt += ans[j];
        }
//      cerr << x << '*' << ' ' << '*' << cnt << endl;
        if(cnt <= k)
            return 1;
        cnt = 0;
    }
    for(long long i = 0; i < m;i++)
        ans[i] = 0;
    return 0;
}
long long bs(long long L,long long R){
//  cerr << L << ' ' << R << endl;
    if(L == R){
        check(L);
        return L;
    }
    long long mid = (L + R+1) >> 1;
    if(check(mid))
        return bs(mid,R);
    return bs(L,mid-1);
}
int main(){
    cin >> n >> m >> k;
    for(long long i = 0; i < n;i++){
        for(long long j = 0; j < m;j++){
            cin >> arr[i][j];
            Max[j][i][0] = arr[i][j];
        }
    }
    for(long long k = 1; k < LOG;k++){
        for(long long j = 0; j < m;j++){
            for(long long i = 0; i < n-(1 << k)+1;i++){
                Max[j][i][k] = max(Max[j][i][k-1],Max[j][i+(1 << (k - 1))][k-1]);
            }
        }
    }
    long long Ans = bs(0,n);
    check(Ans);
    for(long long i = 0; i < m;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}