#include <iostream>
#include <map>
using namespace std;
const int N = 200000+10;

typedef unsigned long long LL;

int n, a[N];
map<int, long long> mp;
long long sum;
int main() {
    scanf("%d", &n);

    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        mp[a[i]] ++;
        sum += a[i];
    }

    LL A=0,B=0;
    for (int i = 1; i <= n; i ++) {
        long long cnt = (n-i+1) - mp[a[i]] - mp[a[i]-1] - mp[a[i]+1];
        long long tmp = (sum - mp[a[i]]*a[i] - mp[a[i]-1]*(a[i]-1) - mp[a[i]+1]*(a[i]+1)) - (LL)cnt * a[i];
        if (tmp > 0) A += tmp;
        if (tmp < 0) B += (-tmp);
        sum -= a[i]; mp[a[i]] --;
    }
    if (A < B) 
        cout << '-';
    if (A < B)
        swap(A,B);
    cout << (A-B) << endl; 

}