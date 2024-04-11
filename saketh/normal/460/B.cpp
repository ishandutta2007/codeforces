#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a, b, c;
vector<long long> soln;

int main(){
    cin >> a >> b >> c;

    for(long long dsum = 1; dsum <=100; dsum++){
        long long x = b * ((long long) round(pow(dsum, a))) + c;

        long long asum  = 0;
        if(x > 0){
            for(long long temp = x; temp; temp /= 10)
                asum += temp % 10;
        }

        if(asum == dsum && 0 < x && x < 1000000000) soln.push_back(x);
    }

    cout << soln.size() << endl;
    for(int i=0; i < soln.size(); i++){
        if(i) cout << " ";
        cout << soln[i];
    }
    cout << endl;
    return 0;
}