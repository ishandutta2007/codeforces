#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    int i = 1;
    while(cnt != n){
        if((i+1)%3!=0&&i%2!=0){
            cnt++;
            i+=5;
            if(cnt == n){
                break;
            }
        }
        i++;
    }
    cout << i*k-k << endl;
    cnt = 0;
    i = 1;
    while(cnt != n){
        if((i+1)%3!=0&&i%2!=0){
            cnt++;
            cout << i*k << " " << (i+1)*k << " " << (i+2)*k << " " << (i+4)*k << endl;
            i+=5;
        }
        i++;
    }
}