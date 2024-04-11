#include <bits/stdc++.h>
using namespace std;

int n;
int num[105];

int main(){
    cin >> n;
    for(int i = 0; i < n/2; i++){
        cin >> num[i];
    }
    sort(num, num+n/2);
    int res1 = 0, res2 = 0;
    for(int i = 0; i < n/2; i++){
        res1 += abs((i*2+1) - num[i]);
        res2 += abs((i*2+2) - num[i]);
    }
    cout << min(res1, res2);

}