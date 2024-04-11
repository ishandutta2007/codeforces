#include <bits/stdc++.h>
using namespace std;

int a[100050];

int main() {
    int n;
    cin >> n;
    int minV = 1e9 + 5;
    int minD = 1e5 + 5;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        minV = min(a[i], minV);
    }
    int lastV = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == minV){
            if(lastV == -1) lastV = i;
            else {
                minD = min(minD, i - lastV);
                lastV = i;
            }
        }
    }
    cout << minD;
    return 0;
}