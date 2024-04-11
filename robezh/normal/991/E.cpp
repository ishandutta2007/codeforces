#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll cnt[15], fac[20], to[15];


ll get(){
    int sum = 0;
    for(int i = 0; i < 10; i++) sum += cnt[i];
    ll res = fac[sum];
    for(int i = 0; i < 10; i++){res /= fac[cnt[i]];}
    return res;
}

ll get_tot(){
    ll res = get();
    if(cnt[0] > 0){cnt[0]--; res -= get(); cnt[0] ++;}

    return res;
}

int main(){
    fac[0] = 1;
    for(int i = 1; i < 20; i++) fac[i] = fac[i-1] * i;
    cin >> n;
    while(n > 0){
        to[n % 10] ++;
        n /= 10;
    }
    ll res = 0;
    ll pro = 1;
    for(int i = 0; i < 10; i++){pro *= (to[i]+1);}
    //cout << "pro = " << pro << endl;
    for(int i = 0; i < pro; i++){
        cnt[0] ++;
        for(int j = 0; j <= 9; j++){
            if(cnt[j] > to[j]) cnt[j+1]++, cnt[j] = 0;
        }
        bool ok = true;
        for(int j = 0; j <= 9; j++){
            if(to[j] != 0 && cnt[j] == 0){ok = false; break;}
        }
        if(!ok) continue;
        //for(int j = 0; j <= 9; j++) cout << cnt[j] << " ";
        //cout << endl;
        res += get_tot();
    }
    cout << res;

}