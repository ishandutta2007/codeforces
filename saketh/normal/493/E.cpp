#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll T, A, B;

bool ex(){
    if(T!=1) return false;
    ll tmp = A;
    while(tmp < B) tmp *= A;
    return tmp == B;
}

int main(){
    cin >> T >> A >> B;

    if((T == A && A != B)){ cout << 0 << endl; return 0; }
    if(T == A && A == B){
        if(T == 1) cout << "inf" << endl;
        else cout << 2 << endl;
        return 0;
    }
    if(A == B){ cout << 1 << endl; return 0; }

    if(T > A){
        if(A == B) cout << 1 << endl;
        else cout << 0 << endl;
        return 0; 
    }

    if(A > B){ cout << 0 << endl; return 0; }

    vector<int> digs;
    for(ll tmp = B; tmp; tmp/=A)
        digs.push_back(tmp%A);

    ll sum = 0, mlt = 1;

    for(int i=0; i<digs.size(); i++){
        sum += mlt * digs[i];
        mlt *= T;
    }

    cout << (sum == A) + ex() << endl;
    return 0;
}