//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> pre;
vector<long long> suf;
const long long Maxn = 1e5 + 1e3;
long long arr[Maxn];
int main(){
    long long n;
    cin >> n;
    long long l = 0;
    for(long long i = 0; i < n;i++)
        cin >> arr[i],l+=arr[i];
    long long sum = 0;
    if(l % 3){
        cout << 0 << endl;
        return 0;
    }
    for(long long i = 0; i < n;i++){
        sum += arr[i];
        if(sum == l/3)
            pre.push_back(i);
    }
    sum = 0;
    for(long long i = n-1; i >= 0;--i){
        sum += arr[i];
        if(sum == l/3)
            suf.push_back(i);
    }
    sort(suf.begin(),suf.end());
    long long ans = 0;
    for(long long i = 0; i < pre.size();i++){
        long long now = pre[i];
        long long addp = upper_bound(suf.begin(),suf.end(),now+1)-suf.begin();
        ans += suf.size()-addp;
    }
    cout << ans << endl;
    return 0;
}