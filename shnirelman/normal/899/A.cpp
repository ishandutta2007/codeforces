#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a == 1)cnt1++;
        else cnt2++;
    }

    if(cnt1 >= cnt2){
        cout << (cnt2 + (cnt1 - cnt2) / 3);
    }
    else {
        cout << cnt1;
    }
}