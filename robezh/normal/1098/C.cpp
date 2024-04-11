#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n;
ll s;
int num[N];
vector<int> res[N];
vector<int> rem[N];
int pt[N];

bool check(int bran){
    vector<int> V;
    ll cur_sum = 0;
    int rem = n;
    ll p = 1, cur = 1;
    while(rem > 0){
        ll take = min((ll)rem, p);
        rem -= take;
        cur_sum += 1LL * take * cur;
        cur++;
        p *= bran;
    }
    return (cur_sum <= s);
}

int main(){
    cin >> n >> s;
    ll mx = 0;
    if(1LL * n * (n + 1) / 2 < s) return !printf("No");
    if(2 * n - 1 > s) return !printf("No");
    int l = 0, r = n-1, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    int bran = r;

    vector<int> V;
    ll cur_sum = 0;
    ll cnt = 1;
    for(int i = 1; i <= n && V.size() < n; i++){
        for(int j = 0; j < cnt && V.size() < n; j++){
            num[i]++;
            V.push_back(i);
            cur_sum += i;
        }
        cnt *= bran;
    }

    s -= cur_sum;
    int dep = V.back();

    for(int i = n; i > 0 && s; i--) {
        while(num[i] > 1 && s) {
            int j = min((ll) dep + 1, i + s);
            num[i] --;
            num[j] ++;
            dep = max(dep, j);
            s -= (j - i);
        }
    }

    int cur = 0;
    for(int i = 1; i <= dep + 1; i++){
        for(int j = 0; j < num[i]; j++){
            res[i].push_back(++cur);
            rem[i].push_back(bran);
        }
    }

    printf("Yes\n");
    for(int i = 2; i <= dep + 1; i++){
        for(int x : res[i]){
            if(rem[i-1][pt[i-1]] == 0) pt[i-1]++;
            rem[i-1][pt[i-1]]--;
            printf("%d ", res[i-1][pt[i-1]]);
        }
    }

}