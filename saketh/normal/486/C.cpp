#include <iostream>
#include <algorithm>
using namespace std;

int N, P;
string s;

int main(){
    cin >> N >> P >> s; P--;
    int l = N/2, r = -1;

    int ans = 0;
    for(int i=0; i<N/2; i++){
        int dist = abs(s[i] - s[N-1-i]);
        ans += min(dist, 26 - dist);
        if(dist) l = min(l, i), r = max(r, i);
    }

    if(P >= (N/2)) P = N-1-P; 
    if(l<=r){
        if(l <= P && P <= r)
            ans += P - l + r - P + min(P - l, r - P);
        else
            ans += max(P - l, r - P);
    }

    cout << ans << endl;
    return 0;
}