#include<iostream>
using namespace std;

int N;
int a, b, c, d;

int main(){
    cin >> N;

    bool done = false;

    for(int i=1; i<=4; i++){
        cin >> a >> b >> c >> d;
        int low_cost = min(a, b) + min(c, d);
        if(low_cost > N) continue;
        cout << i << " " << min(a, b) << " " << N - min(a, b) << endl;
        done = true;
        break;
    }

    if(!done) cout << "-1" << endl;
    return 0;
}