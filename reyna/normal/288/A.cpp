#include <iostream>
using namespace std;
int main(){
    int n;
    int k;
    cin >> n >> k;
    if(k == 1){
        if(n == 1){
            cout << "a";
            return 0;
        }
        cout << -1;
        return 0;
    }
    if(k > n){
        cout << -1;
        return 0;
    }
    int counter = 0;
    int a = 2;
    if(k == 2){
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                cout << "a";
            }else{
                cout << "b";
            }
        }
    }else{
        for(int i = 0; i < n;i++){
            if(n-counter == k-2){
                cout << char('a'+a);
                a++;    
            }else{
                if(i%2 == 0){
                    cout << "a";
                }else{
                    cout << "b";
                }
                counter++;
            }
        }
    }
}