#include <bits/stdc++.h>
using namespace std;

int n;
int num[205];

int main(){
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i++) cin >> num[i];
    int cnt = 0;
    int cur = 0;
    for(int i = 0; i < n; i+=2){
        if(num[i] != num[i+1]){
            int ai, tmp;
            for(int j = i+2; j < n; j++){
                if(num[j] == num[i]){
                    ai = j; break;
                }
            }
            tmp = num[ai];
            cnt += (ai - (i+1));
            for(int j = ai; j >= i+2; j--) num[j] = num[j-1];
            num[i+1] = tmp;
        }
//        for(int i = 0; i < n; i++) cout << num[i] << " ";
//        cout << endl;
    }
    cout << cnt;

}