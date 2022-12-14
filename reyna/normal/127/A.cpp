#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a,b;
    cin >> a >> b;
    int last1 = a;
    int last2 = b;
    double counter = 0;
    for(int i = 1; i < n;i++){
        int a,b;
        cin >> a >> b;
        counter += sqrt(pow((last1-a),2) + pow((last2-b),2));
        last1 = a;
        last2 = b;
    }
    cout.precision(10);
    cout << counter*k/50 << endl;
    return 0;
}