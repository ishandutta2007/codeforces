#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;
ll tot;
vector<int> A, B;

int main(){
    cin >> a >> b;
    tot = a + b;
    ll r = 0;
    while((r+1)*(r+2)/2 <= tot) r++;

    ll ex = -1, l = 0;

    while((l+1) * (l+2) / 2 <= a && l + 1 <= r) l++;

    if(l*(l+1)/2 < a && l + 1 <= r){
        l++;
        ex = l * (l + 1) / 2 - a;
    }

    for(int i = 1; i <= l; i++){
        if(i != ex) A.push_back(i);
    }
    if(ex != -1) B.push_back(ex);
    for(int i = l + 1; i <= r; i++){
        B.push_back(i);
    }
    printf("%d\n", A.size());
    for(int x : A) cout << x << " ";
    printf("\n%d\n", B.size());
    for(int x : B) cout << x << " ";


}