//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
struct marb{
    long long x,c;
    marb(){
        
    }
    marb(int x,int c){
        this->x = x;
        this->c = c;
    }
};
bool cmp(marb a,marb b){
    if(a.x > b.x)
        return 1;
    return 0;
}
const long long oo = (long long)1 << 60;
const int Maxn = 3e3 + 20;
marb arr[Maxn];
long long sum[Maxn];
long long dp[Maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int x,c;
        cin >> x >> c;
        arr[i] = marb(x,c);
    }
    sort(arr,arr+n,cmp);
    sum[0] = 0;
    for(int i = 1; i < n;i++)
        sum[i] = sum[i-1] + arr[i].x;
    for(int i = 1; i <= n;i++)
        dp[i] = oo;
    for(int i = 1; i <= n;i++){
//      cerr << arr[i-1].x << endl;
        for(int j = 0; j < i;j++){
//          cerr << endl;
//          cerr << i << " " << j << " " << sum[i-1] - sum[j] + arr[j].x << endl << endl;
            dp[i] = min(dp[i],arr[i-1].c + (abs((i - j) * arr[i-1].x - (sum[i-1] - sum[j] + arr[j].x))) + dp[j]);
        }
//      cerr << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}