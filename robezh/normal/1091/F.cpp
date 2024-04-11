#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n;
ll L[N];
string T;
bool hadwater = false;
ll stamina = 0, twicegrass = 0;
ll tim = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> L[i];
    cin >> T;

    for(int i = 0; i < n; i++){
        if(T[i] == 'L'){
            stamina -= L[i];
            tim += L[i];
            if(stamina < 0){
                tim -= stamina * (hadwater ? 3 : 5);
                stamina = 0;
            }
        }
        else if(T[i] == 'W') {
            hadwater = true;
            tim += L[i] * 3;
            stamina += L[i];
        }
        else {
            tim += L[i] * 5;
            stamina += L[i];
            twicegrass += 2 * L[i];
        }
        twicegrass = min(twicegrass, stamina);
    }

    if(stamina > 0){
        tim -= (5 - 1) * twicegrass / 2;
        tim -= (3 - 1) * (stamina - twicegrass) / 2;
    }

    cout << tim << endl;
}