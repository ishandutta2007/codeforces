#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int X,d;
int n = 0;
ll curk = 30, curnum = 1;
vector<ll> res;

int main(){
    cin >> X >> d;
    while(X > 0){
        if(X >= (1<<curk)-1){
            for(int i = 0; i < curk; i++){
                res.push_back(curnum);
            }
            X -= (1<<curk)-1;
            curnum += (d+1);
        }
        else{
            curk--;
        }
        if(curk == 0) break;
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";

}