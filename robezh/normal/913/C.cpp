#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18 + 15;


ll n, L;
ll c[35];
bool fu[35];

int main() {
    //cout << INF;
    fill(fu, fu+35, false);
    ll res = 0;
    cin >> n >> L;
    for(int i = 0; i < n; i++) cin >> c[i];
    double k = 10000000000005;
    for(int i = 0; i < n; i++){
        if(k < (double)c[i] / (double)(1<<(i))){
            fu[i] = true;
        }
        else{
            k = (double)c[i] / (double)(1<<(i));
        }
    }
    //cout << "fu: ";
//    for(int i = 0; i < n; i++){
//        cout << fu[i] << " ";
//    }
//    cout << endl;
    int pos = n-1;

    ll minV = INF;
    ll cumul = 0;
    while(L > 0){
//        if((1<<pos) > L){
//            minV = min(minV, (ll)c[pos]+cumul);
//            pos--;
//        }
            if(fu[pos]){
                pos--;
            }
            else{
                ll vol = L / (1<<pos);
                //cout << "vol : " << vol << endl;
                cumul += vol * c[pos];
                L -= vol * (1 << pos);
                minV = min(minV, (ll)c[pos]+cumul);
                //if(L == 0) good = true;
                pos--;
            }
    }

    minV = min(minV, cumul);
    cout << minV;
}