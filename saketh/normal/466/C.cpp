#include <iostream>
using namespace std;

int N;
long long sum = 0;
long long val[500005];
long long pref[500005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> val[i];
        sum += val[i];
    }

    if(sum % 3){
        cout << 0 << endl;
        return 0;
    }

    pref[0] = val[0];
    for(int i=1; i<N; i++)
        pref[i] = pref[i-1] + val[i];

    int tt = 0;
    for(int j=0; j<N-1; j++)
        if(pref[j] == 2 * sum / 3)
            tt++;

    long long ans = 0;
    for(int i=0; i<N-1; i++){
        if(pref[i] == 2 * sum / 3)
            tt--;
        if(pref[i] == sum / 3)
            ans += tt;
    }
    cout << ans << endl;
    return 0;
}