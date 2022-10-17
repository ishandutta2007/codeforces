#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, v[128];
long long A, B;
vector<int> mid;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> C;
        for(int j=0; j<C; j++){
            cin >> v[j];
            if(2*j == C-1) mid.push_back(v[j]);
            else if(2*j < C-1) A += v[j];
            else B += v[j];
        }
    }

    sort(mid.begin(), mid.end(), greater<int>());
    for(int i=0; i<mid.size(); i++)
        if(i&1) B += mid[i];
        else A += mid[i];

    cout << A << " " << B << endl;
    return 0;
}