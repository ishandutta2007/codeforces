#include <bits/stdc++.h>
using namespace std;

int n;
int base = 100500;
int num[100500];
int cnt[3];


int main(){
    fill(cnt, cnt+3, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        base = min(base, num[i]);
    }
    for(int i = 0; i < n; i++){
        num[i] -= base;
        cnt[num[i]] ++;
    }
    if(cnt[2] == 0){
        cout << n << endl;
        for(int i = 0; i < n; i++){
            cout << num[i] + base << " ";
        }
        return 0;
    }


    int cnt1 = cnt[1] / 2 * 2;
    int cnt2 = min(cnt[0],cnt[2]) * 2;
    if(cnt1 > cnt2){
        int res = n - cnt1;
        cout << res << endl;
        for(int i = 0; i < cnt[0] + cnt1/2; i++) cout << base << " ";
        for(int i = 0; i < cnt[2] + cnt1/2; i++) cout << base + 2 << " ";
        if(cnt[1] % 2 == 1) cout << base + 1;
    }
    else{
        int res = n - cnt2;
        cout << res << endl;
        for(int i = 0; i < cnt[0] - cnt2/2; i++) cout << base << " ";
        for(int i = 0; i < cnt[2] - cnt2/2; i++) cout << base + 2 << " ";
        for(int i = 0; i < cnt[1] + cnt2; i++) cout << base + 1 << " ";
    }
}