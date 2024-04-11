#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int left = n;
    int counter = 0;
    for(int i = 1; left > 0; ++i){
        ++counter;
        --left;
        if(i % m == 0){
            ++left;
        }
    }
    cout << counter;
    return 0;
}