#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;
string longstr;
int k;
ll C[1005][1005];
ll pre[1005];

void set_C(){
    for(int i = 0; i < 1005; i++) C[i][0] = 1;
    for(int i = 1; i < 1005; i++){
        for(int j = 1; j < 1005; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}

int get_order(int k){
    int cnt = 0;
    while(k > 1){
        int p = 0;
        while(k > 0){
            p += k % 2;
            k /= 2;
        }
        k = p;
        cnt ++;
    }
    return cnt;
}

ll get_final(string str, int t){
    if(t == 0) return 1;
    if(t > str.length()) return 0;

    if(str[0] == '0') return get_final(str.substr(1,str.length()), t);
    if(str[0] == '1'){
        return (get_final(str.substr(1,str.length()), t-1) + C[str.length()-1][t]) % mod;
    }
}



int main(){
    set_C();
    for(int i = 1; i <= 1000; i++){
        pre[i] = get_order(i);
    }
    getline(cin, longstr);
    cin >> k;
    if(k == 0) return !printf("1\n");
    if(k == 1) return !printf("%d", get_final(longstr, 1) - 1);
    ll ans = 0;
    for(int i = 1; i <= 1000; i++){
        if(pre[i] == k-1){

            //cout << i << " is good, ans is " << get_final(longstr, i) << endl;
            ans = (ans + get_final(longstr, i)) % mod;
        }
    }
    printf("%d", ans);
//    set_C();
//    cout << get_final("111",2);
}