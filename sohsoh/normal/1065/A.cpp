#include <iostream>
#include <vector>

using namespace std;

vector<long long int> out;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long int s, a, b, c;
        cin >> s >> a >> b >> c;
        long long int x = s / c;
        out.push_back(x + (x / a) * b);
    }
    for(int i = 0; i < n; i++){
        cout << out[i] << endl;
    }
    return 0;
}