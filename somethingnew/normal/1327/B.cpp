#include <iostream>
using namespace std;
int main(){
    int i;
    cin >> i;
    for (; i > 0; --i) {
        int n = 0;
        cin >> n;
        int prince[n] = {};
        int princess[n] = {};
        for (int j = 0; j < n; ++j) {
            int kl;
            cin >> kl;
            int tr = 1;
            for (int k = 0; k < kl; ++k) {
                int hh;
                cin >> hh;
                if(tr and prince[hh - 1] == 0){
                    prince[hh - 1] = 1;
                    princess[j] = 1;
                    tr = 0;
                }
            }
        }
        int pos1 = -1;
        int pos2 = -1;
        for (int pr = 0; pr < n; ++pr) {
            if(prince[pr] == 0){
                pos1 = pr;
            }
            if(princess[pr] == 0){
                pos2 = pr;
            }
        }
        if(pos1 != -1){
            cout << "IMPROVE" << endl;
            cout << pos2 + 1 << ' ' << pos1 + 1 << endl;
        } else{
            cout << "OPTIMAL" << endl;
        }
    }
}