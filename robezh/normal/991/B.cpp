#include <bits/stdc++.h>
using namespace std;

int n;
int num[105];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    int cnt = 0;
    while(true){
        int tot = 0;
        for(int i = 0; i < n; i++) tot += num[i];
        double mean = (double)tot / n;
        if(mean >= 4.5) break;

        int mi = 0;
        for(int i = 0; i < n; i++){
            if(num[i] < num[mi]) mi = i;
        }
        num[mi] = 5;
        cnt ++;
    }
    cout << cnt;
}