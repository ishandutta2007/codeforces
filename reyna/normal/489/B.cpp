#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int g[123];
int b[123];
int main(){
    int boys,girls;
    cin >> boys;
    for(int i = 0; i < boys;i++){
        cin >> b[i];
    }
    cin >> girls;
    for(int i = 0; i < girls;i++){
        cin >> g[i];
    }
    sort(b,b+boys);
    sort(g,g+girls);
    int cnt = 0;
    int ptr = -1;
    for(int i = 0; i < boys;i++){
        while(ptr++ || 1){
        //      cerr << ptr << " " << i << endl;
            if(ptr == girls)
                break;
            if(abs(g[ptr]-b[i])<=1){
                cnt++;
                break;
            }
            if(g[ptr] > b[i]+1){
                ptr--;
        //      cerr << i << endl;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}