#include <bits/stdc++.h>
using namespace std;

bool isNumberLucky(int maybeLucky){
    string luckier = to_string(maybeLucky);
    bool isLucky = true;
    for(int asdf = 0; asdf < luckier.length(); asdf++){
        if(luckier[asdf] != '4' && luckier[asdf] != '7'){
            isLucky = false;
        }
    }

    return isLucky;
}

int main(){
    int N;
    cin >> N;

    for(int i=1; i<N+1; i++){
        if(N % i == 0){
            if(isNumberLucky(i)){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}