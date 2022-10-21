#include <bits/stdc++.h>
using namespace std;


int n,m;
bool good[30];
int ans;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cout << 1 << endl;
        fflush(stdout);
        cin >> ans;
        if(ans == 0) return 0;
        good[i] = (ans == 1);
    }
    int cur = 0;
    int l = 1, r = n, mid;
    while(true){
        mid = (l + r) / 2;
        cout << mid << endl;
        fflush(stdout);
        cin >> ans;
        if(ans == 0) return 0;
        if(!((ans==1) ^ good[(cur++)%m])) l = mid + 1;
        else r = mid - 1;
    }
}