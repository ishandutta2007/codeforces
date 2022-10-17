#include <iostream>
using namespace std;

int N;
int val[1005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> val[i];

    int ans = 0;
    int run = 0;

    for(int i=0; i<N; i++){
        if(val[i] == 0){
            if(run) ans += run + 1;
            run = 0;
        }
        else run++;
    }
    if(run) ans += run + 1;

    if(ans) cout << ans-1 << endl;
    else cout << 0 << endl;
    return 0;
}