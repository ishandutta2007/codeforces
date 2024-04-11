#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    string dirs;
    cin >> dirs;

    int count = 0;
    bool currUp; //currently we are on the top one if true and vice versa
    if(dirs[0] == 'U'){
        currUp = true;
    } else{
        currUp = false;
    }

    int currDiff = 0; //diff represents the difference between up and right

    for(int i=0; i<N; i++){
        if(dirs[i] == 'U'){
            currDiff++;
            if(currUp == false && currDiff > 0){
                currUp = true;
                count++;
            }
        } else{
            currDiff--;
            if(currUp == true && currDiff < 0){
                currUp = false;
                count++;
            }
        }
    }

    cout << count;

    return 0;
}