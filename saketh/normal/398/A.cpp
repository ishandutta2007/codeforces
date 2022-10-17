#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll A, B, ans = -0x7fffffff;
ll bxb, bex, bob, bpb;

int main(){
    cin >> A >> B;

    if(B == 0){
        cout << A*A << endl;
        for(int i=0; i<A; i++) cout << "o";
        cout << endl;
        return 0;
    }

    if(B == 1){
        cout << A*A - 1 << endl;
        for(int i=0; i<A; i++) cout << "o";
        cout << "x" << endl;
        return 0;
    }

    if(A == 0){
        cout << -B*B << endl;
        for(int i=0; i<B; i++) cout << "x";
        cout << endl;
        return 0;
    }

    for(int xb = 2; xb <= min(B, A+1); xb++){
        int ob = xb - 1;

        ll score = ob - 1;
        score += (A - (ob-1)) * (A - (ob-1));;
        
        ll pb = B / xb;
        ll ex = B % xb;

        score -= (xb - ex) * pb * pb;
        score -= ex * (pb+1) * (pb+1);

        if(score > ans){
            ans = score;
            bxb = xb;
            bex = ex;
            bob = ob;
            bpb = pb;
        }
    }

    cout << ans << endl;
    for(int i=0; i<bxb; i++){
        for(int j=0; j<bpb; j++) cout << "x";
        if(i < bex) cout << "x";
        if(i==0) for(int j=0; j<A-(bob-1); j++) cout << "o";
        else if(i+1 < bxb) cout << "o";
    }
    cout << endl;
    return 0;
}