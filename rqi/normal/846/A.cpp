#include <bits/stdc++.h>

using namespace std;


int main() {
    int ans = -1;
    int n;
    cin >> n;
    int array[n];
    int ans1 = n;
    int num1 = 0;
    for(int i = 0; i < n; i++){
        cin >> array[i];
        if(array[i] == 1){
            num1++;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(i != 0){
            if(array[i] == 1 && array[i-1] != 1){
                for(int j = i+1; j < n; j++){
                    if(array[j] == 0){
                       ans1--;
                    }
                }
                for(int j = i-1; j > -1; j--){
                if(array[j] == 1){
                    ans1--;
                }
            }
            ans = max(ans, ans1);
            ans1 = n;
            }
            
        }
        else{
            if(array[i] == 1){
            for(int j = i+1; j < n; j++){
                if(array[j] == 0){
                    ans1--;
                }
            }
            ans = max(ans, ans1);
            ans1 = n;
            }
        }
    }
    ans = max(ans, n-num1);
    cout << ans;
}