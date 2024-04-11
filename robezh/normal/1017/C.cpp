#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    //if(n == 3){return !printf("1 2 3");}
    int sqr = 0;
    while(sqr * sqr < n) sqr ++;
    int cur = n;
    for(int i = 0; i < sqr; i++){
        stack<int> S;
        for(int j = 0; j < sqr && cur >= 1; j++){
            S.push(cur--);
        }
        while(!S.empty()){
            cout << S.top() << " ";
            S.pop();
        }
    }
}