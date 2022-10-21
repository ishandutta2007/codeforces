#include <iostream>

using namespace std;

int main() {
    int x = 0;
    int N;
    int a,b;
    int P = 0;
    bool increasing = false;
    bool equal = false;
    bool decreasing = false;
    int ans = 0;
    cin >> N;
    if(N > 2){
        
    
    cin >> a >> b;
    if(a > b){
        decreasing = true;
    }
    if(a == b){
        equal = true;
    }
    if(a < b){
        increasing = true;
    }
    P = b;
    for(int i = 2; i < N; i++){
        cin >> x;
        if(x > P){
            if(increasing == 0){
            ans = 1;
            break;
            }
            
        }
        else if(x == P){
            if(increasing){
                increasing = false;
                equal = true;
            }
            else if(decreasing){
                ans = 1;
                break;
            }
        
        }
        else if(x < P){
            if(increasing){
                increasing = false;
                decreasing = true;
               
            }
            else if(equal){
                decreasing = true;
                equal = false;
            }
        }
        P = x;
    }
    if(ans == 0){
        cout << "YES";
    }
    if(ans == 1){
        cout << "NO";
    }
    }
    else{
        cout << "YES";
    }
}