#include <iostream>
#include <cstdlib>
using namespace std;

string inp;

int main(){
    cin >> inp;
    int N = inp.size();

        for(int i=0; i<N; i++){
            int v1 = inp[i] - '0';
            if(v1 % 8 == 0){ cout << "YES\n" << v1 << endl; return 0; }
            for(int j=i+1; j<N; j++){
                int v2 = 10 * v1 + inp[j] - '0';
                if(v2 % 8 == 0){ cout << "YES\n" << v2 << endl; return 0; }
                for(int k=j+1; k<N; k++){
                    int v3 = v2 * 10 + inp[k] - '0';
                    if(v3 % 8 == 0){ cout << "YES\n" << v3 << endl; return 0; }
                }
            }
        }

    cout << "NO\n";
}