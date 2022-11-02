#include <bits/stdc++.h>
using namespace std;

bool isNumberLucky(long long maybeLucky){
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
    long long N;
    cin >> N;

    string hi = to_string(N);

    int luckyCount = 0;

    for(int i=0; i<hi.length(); i++){
        if(hi[i]=='4' || hi[i]=='7'){
            luckyCount++;
        }
    }

    if(isNumberLucky(luckyCount)){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}