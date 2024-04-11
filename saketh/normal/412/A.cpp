#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
string t;

int main(){
    cin >> N >> K;
    cin >> t;

    if((K-1) < (N-K)){  //go left
        for(int i=1; i<K; i++)
            cout << "LEFT" << endl;
        for(int i=0; i<t.length(); i++){
            if(i) cout << "RIGHT" << endl;
            cout << "PRINT " << t[i] << endl;
        }

    }
    else{
        for(int i=0; i<(N-K); i++)
            cout << "RIGHT" << endl;
        for(int i=N-1; i>=0; i--){
            if(i<N-1) cout << "LEFT" << endl;
            cout << "PRINT " << t[i] << endl;
        }
    }

    return 0;
}