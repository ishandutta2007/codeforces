#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n;
ll k;
int nums[N], a[N];
struct BIT{
    int bit[N];
    int get(int i){
        if(i < 0) return 0;
        int ans = 0;
        while(i){ans += bit[i]; i -= (i&-i);}
        return ans;
    }
    int add(int i, int val){
        while(i < N){bit[i] += val; i += (i&-i);}
    }
}b[2];


int main(){
    scanf("%d%I64d", &n, &k);
    for(int i = 0; i < n; i++){scanf("%d", &nums[i]); a[i] = nums[i];}
    sort(a, a + n);
    for(int i = 0; i < n; i++) nums[i] = int(lower_bound(a, a + n, nums[i]) - a) + 1;

    ll res = 0, cur = 0;
    int r = 0;
    for(int i = 0; i < n; i++){
        cur += b[1].get(nums[i]);
        b[1].add(nums[i], 1);
    }
    cur = 1LL * n * (n-1) / 2 - cur;

    for(int i = 0; i < n; i++){
        cur += i - b[0].get(nums[i]);
        cur += b[1].get(nums[i] - 1);
        b[0].add(nums[i], 1);

        while(r == i || (r < n && cur > k)){
            b[1].add(nums[r], -1);
            cur -= b[0].get(n) - b[0].get(nums[r]);
            cur -= b[1].get(nums[r] - 1);
            r++;
        }
        res += n - r;
    }
    printf("%I64d\n", res);

}