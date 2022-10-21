#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[100050];
ll ca[200050];
int s,f,d;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 2*n; i++) ca[i] = a[i%n];
    scanf("%d%d", &s, &f);
    d = f-s;
    ll sum = 0;
    int maxi = -1;
    ll maxsum = -1;
    int res = -1;
    for(int i = 0; i < d; i++) sum += ca[i];
    for(int i = 0; i < 2*n-d; i++){
        if(sum > maxsum){
            maxi = i, maxsum = sum;
            res = (s-maxi+10*n) % n;
            if(res == 0) res += n;
        }
        if(sum == maxsum){
            maxi = i;
            int newres = (s-maxi+10*n) % n;
            if(newres == 0) newres += n;
            if(newres < res) res = newres;
        }
        sum += ca[i+d];
        sum -= ca[i];

    }
    cout << res;
}