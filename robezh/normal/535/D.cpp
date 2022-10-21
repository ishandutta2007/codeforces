#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000050

typedef long long ll;
const ll mod = 1e9 + 7;

string str;
int Z[MAXN], a[MAXN];
bool good[MAXN];

void setZ(){
    int n = str.length();
    int L, R, k;

    Z[0] = n;
    L = R = 0;

    for(int i = 1; i < n; i++){
        if(i > R){
            L = R = i;
            while(R < n && str[R] == str[R-L]) R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;

            if(Z[k] < R-i+1){
                Z[i] = Z[k];
            }
            else{
                L = i;
                while(R < n && str[R] == str[R-L]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    cin >> str;
    for(int i = 0; i < k; i++) scanf("%d", &a[i]);
    setZ();
    fill(good, good + MAXN, false);
    for(int i = 0; i < str.length(); i++) good[i] = (Z[i] == str.length()-i);
    int cnt = (k == 0 ? n : a[0] - 1 + (n - a[k-1] - (int)str.length() + 1));
    for(int i = 1; i < k; i++){
        if(a[i] - a[i-1] >= str.length()) cnt += a[i]-a[i-1]-(int)str.length();
        else if(!good[a[i]-a[i-1]]){
            return !printf("0");
        }
    }
    ll res = 1;
    for(int i = 0; i < cnt; i++) res = (res * 26) % mod;
    cout << res;
}