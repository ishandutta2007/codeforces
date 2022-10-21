#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll res = 0;
int bit[60];
ll num[60];
int cnt = 0;

int main(){
    cin >> n;
    while(n != 0){
        bit[cnt++] = (int)(n % 2);
        n /= 2;
    }
    int k = 0;
    for(int i = 0; i < cnt; i++) if(bit[i]) num[k++] = i;
    for(int i = 0; i < k; i++) res += 1LL * num[i] * ((ll)1 << (num[i]-1));
    //cout << res << endl;
    //for(int i = 0; i < k; i++) cout << num[i] << " ";
    for(int i = 1; i < k; i++) res += ((ll)1 << num[i]);
    cout << res << endl;
}