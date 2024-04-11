#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n,k,l,t;
int num[N];

int main(){
    scanf("%d%d%d", &n, &k, &l);
    t = n * k;
    for(int i = 0; i < t; i++){scanf("%d", &num[i]);}
    sort(num, num+t);
    auto m = upper_bound(num, num+t, num[0]+l) - num;
    stack<int> S;
    if(n > m) return !printf("0");
    int rem = n;
    ll sum = 0;
    for(int i = 0; i < m; i++){
        if(i % k == 0 && rem > 0){sum += num[i]; rem--;}
        else{S.push(num[i]);}
    }
    while(rem--){
        sum += S.top();
        S.pop();
    }
    cout << sum;


}