#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,a,k;
    cin >> n >> a >> k;
    for(int i = 0; i <= 2*k; i++){
        int current = a-k+i;
        if(current != a){
            if(current > 1 && i == 0){
                cout << "<< " << current << " ";
            }else if(current < n && i == (2*k)){
                cout << current << " >>";
            }else if(current >= 1 && current <= n){
                cout << current << " ";
            }
        }else if(current == a){
            if(current > 1 && i == 0){
                cout << "<< (" << current << ") ";
            }else if(current < n && i == (2*k)){
                cout << "(" << current << ") >>";
            }else if(current >= 1 && current <= n){
                cout << "(" << current << ") ";
            }
        }
    }
}