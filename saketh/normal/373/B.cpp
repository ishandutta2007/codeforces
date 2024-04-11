#include<iostream>
using namespace std;

long long funds, start, cost, ans;

long long ndig(long long arg){
    if(arg < 10) return 1;
    return 1 + ndig(arg/10);
}

long long nnum(long long dig){
    if(dig == 1) return 9;
    else return 10*nnum(dig-1);
}

long long bnum(long long dig){
    if(dig == 1) return 9;
    else return 9 + 10 * bnum(dig-1);
}

int main(){
    cin >> funds >> start >> cost;
    funds /= cost;
    
    long long dig = ndig(start);
    while(dig <= funds){
        long long rem = bnum(dig) - start + 1;
        if(rem * dig <= funds){
            ans += rem;
            funds -= rem * dig;
            start = bnum(dig) + 1;
            dig++;
        }
        else{
            ans += funds/dig;
            break;
        }
    }
    
    cout << ans << endl;
}