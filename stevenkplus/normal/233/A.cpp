#include <iostream>

using namespace std;

const int MAXN = 110;

int main() {
    int N;
    cin >> N;   
    if(N &1) {
        cout << -1<<endl;
    }
    else {
        for(int i = 0; i < N; ++i) {
            if(i&1) cout << i;
            else cout << i + 2;
            if(i==N-1) cout<<endl;  
            else cout<<" ";
        }
    }
}