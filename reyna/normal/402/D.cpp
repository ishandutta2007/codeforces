//In the name of God
#include <iostream>
#include <map>
using namespace std;
map<int,int> bad;
const int Maxn = 5e3 + 50;
int num[Maxn];
int arr[Maxn];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int n,m;
    cin >> n >> m;
    int g = 0;
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    for(int i = 0; i < m;i++){
        int b;
        cin >> b;
        bad[b] = -2;
    }
    int init = 0;
    for(int i = 0; i < n;i++){
        int now = arr[i];
        int cnt = 0;
        for(int j = 2;j * j <= arr[i];j++){
            while(arr[i] % j == 0){
                arr[i]/=j;
                cnt += bad[j]+1;
            }
        }
        if(arr[i]-1)
            cnt += bad[arr[i]]+1;
        init += cnt;
        if(!i)
            g = now;
        g = gcd(max(now,g),min(now,g));
        int tmp = g;
        cnt = 0;
        for(int j = 2; j * j <= g;j++){
            while(tmp % j == 0){
                tmp/=j;
                cnt += bad[j]+1;
            }
        }
        if(tmp-1){
            cnt += bad[tmp]+1;
        }
        num[i] = -cnt;
    }
    int now = 0;
    int ans = 0;
    for(int i = n-1; i + 1;i--){
        if(num[i]-now >= 0)
            ans+=(num[i]-now)*(i+1),now = num[i];
    }
    cout << init+ans << endl;
    return 0;
}